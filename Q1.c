#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/timeb.h>

//2.2 A program to implement the Horspool’s algorithm. (20%)
//Essentially turns file into an array
#define LENGTH 2045

//Remove spaces from a line that would otherwise ruin the word count
char* normalizedLine(char *selectedLine){
    char *line = malloc(256);
              strtok(selectedLine, "\n"); // remove any newlines
               char *tempWord = strtok(selectedLine, " "); //gets the first word
                while(tempWord != NULL) {
                  strcat(line, tempWord);
                  strcat(line, " \0");
                  tempWord = strtok(NULL, " "); //Resets
                }
    return line;
}

void OptimalBST(char *word){
 long n = strlen(word);
    char C[n][n];
    char* R[n][n];
    
    //randomly assigns the first number
    float lastNum = 0;
    srand((unsigned)time(NULL));
    for (int i = 0; i < strlen(word); i++) {
        //move time
        float prob = ((float)rand()/RAND_MAX) * 10;
        lastNum = prob;
        C[0][0] = prob;
      //  sprintf(C[i][i], "%d", i);
        if(i == 2){
            //C[0][0] = prob;
        }
        

    }
    float total = 0;
    int l = 0;
    while (true) {
        
        float prob = (float)rand()/RAND_MAX;
        //change decimal places
        
        float value = floorf(prob * 10) / 10;
        if(value  < 0.1){
            value = 0.1;
        }
        C[l][l] = (value) * 10;
        total += value;
        l++;
        if(l == 3){
        if((total == 1.0) && ((l) == (strlen(word))) ){
            printf("\ngood\n");
            break;
        }
        else{
            total = 0;
            l = 0;
        }
                   }
    }
    
    for (int i = 0; i < n; i++) {
        
  
        printf("%d\n", C[i][i]);
        
        

    }
        for (int i = 1; i < n; i++) {
        C[i][i - 1] = 0;
        C[i][i] = word[i];
        R[i][i] = i;
        C[n+1][n] = 0;
        int sum = 0;
        for (int d = 1; d < n-1; d++) {
            for (i = 1; i < n - d; i++) {
                int j = i + d;
                int minVal = 9999;
                int kmin = 0;
                for (int k = i; k < j; k++) {
                    if((C[i][k-1] + C[k + 1][j]) < minVal){
                        minVal = C[i][k - 1] + C[k + 1][j];
                        kmin = k;
                        
                    }
                }
                R[i][j] = kmin;
                sum = word[i];
                for (int s = i+1; s < j; s++) {
                    sum = sum + word[s];
                }
                C[i][j] = minVal + sum;
                
                
            }
        }

    }
}

void dataToArray(FILE *fp, char arr[LENGTH][LENGTH]){
      char buff[256];

        if (fp != NULL)
        {
            int length = 0;
            int currLine = 0;
            int i = 0;
            int j=0; int index=0;
            char *word = NULL;
            char *temp[1000];
            while (fgets(buff, 256, fp) != NULL)
            {
            
                temp[i] = malloc(strlen(buff) + 5 );
        
                strcpy(temp[i], buff);
                i++;
                length++;
                
                
            }
            
        
            while (currLine != length) {
                word = malloc(2156);
                if(temp[currLine] == NULL ){
                    currLine++;
                    free(word);
                    continue;
                    
                }
                strcpy(word, temp[currLine]);
             
           char *line = normalizedLine(word);
           
       for(i=0;i<(strlen(line));i++)
                                               {
                                                   
                                                   if(line[i]==' '||line[i]=='\n')
                                                   {
                                           
                                           
                                                       arr[index][j]='\0';
                                                       j=0;
                                                       index++;
                                                      
                                                       
                                                   }
                                                   else
                                                   {
                                                     
                                                      // printf("%c", word[i]);
                                                       arr[index][j]=line[i];
                                                       j++;
                                                       
                                                   }
                                               }

                //reset
                
                free(word);
                currLine++;
            }
          

        }
        else
        {
            printf("unable to open file");
        }

}
int main(int argc, const char * argv[]) {

//Neccessary structs to find time
     struct timeb firstStart, firstEnd;
       int elapsedTime = 0;
     ftime(&firstStart);

   FILE *fp = fopen("data_7.txt", "r");
   //Length-1 of data_4.txt (adjust according to length of file)
   int length = LENGTH;
   char array[length][length];
   
   dataToArray(fp, array);
    printf("%s", array[2045]);
    
    
    
    
    
    
    
    
    
    
    
    

       //Calculating the total time & if the time is less than 0ms, set to 0
       ftime(&firstEnd);
         elapsedTime =  firstEnd.millitm - firstStart.millitm;
         if(elapsedTime <=0){
             elapsedTime = 0;
         }
     // printf("\nelasedTime for Horspool's technique %dms\n", elapsedTime);
       return 0;
    
}