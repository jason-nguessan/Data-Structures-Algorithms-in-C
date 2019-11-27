/*
full name: Jason Eddy N'Guessan, student ID number: 1079936, and uoguelph e-mail: jnguessa@uoguelph.ca
 */
#if !defined(text_h)
#define text_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node_struct
{
    void *data;

    struct node_struct *next;
};

char *get_word(struct node_struct **list);
struct node_struct *txt2words(FILE *fp);
struct node_struct *search(struct node_struct *list, char *target, int (*compar)(const void *, const void *));
struct node_struct *copy(struct node_struct *start, struct node_struct *end);
int ftext(FILE *fp, struct node_struct *list);
struct node_struct *sort(struct node_struct *list, int (*compar)(const void *, const void *));

void remove_repeats(struct node_struct *list, int (*compar)(const void *, const void *));
int length(struct node_struct *list);
void free_list(struct node_struct *list, int free_data);
#endif