```
int findLength(int* A, int ASize, int* B, int BSize)
{
    int length = 0;
    int *matrix;
    int i;
    int j;

    if ((A == NULL) || (B == NULL))   return 0;
    if ((ASize == 0) || (BSize == 0))  return 0;

    matrix = (int *)malloc((BSize + 1) * sizeof(int));
    memset((void *)matrix, 0, (BSize + 1) * sizeof(int));

    for(i = 0; i < ASize; i++) {
        for(j = BSize - 1; j >= 0; j--) {
            if(A[i] == B[j]) {
                matrix[j + 1] = matrix[j] + 1;
                length = max(length, matrix[j + 1]);
            }
            else {
                matrix[j + 1] = 0;
            }      
        }
    }
    return length;
}
```
```
#define max(A, B) ((A) >= (B)) ? (A) : (B)
//#define MAXSIZE 1001


int findLength(int* A, int ASize, int* B, int BSize)
{
    if(!A||!B)
     return 0;
    if(ASize==0||BSize==0)
     return 0;
    int **matrix = (int**)malloc(sizeof(int*)*(ASize+1));
   //int matrix[MAXSIZE][MAXSIZE]={0};
    
    int i,j,maxlen=0;
    for(i=0;i<=ASize;i++)
        matrix[i]=(int*)malloc(sizeof(int)*(BSize+1));
    for(i=0;i<ASize;i++)
    {
       matrix[i][0]=0;
    }
    for(j=0;j<BSize;j++)
    {
        matrix[0][j]=0;
    }
    for(i=1;i<=ASize;i++)
    {
        for(j=1;j<=BSize;j++)
        {
            if(A[i-1]==B[j-1])
            {
                matrix[i][j]=matrix[i-1][j-1]+1;
                maxlen=max(matrix[i][j],maxlen);
            }
            else
             matrix[i][j]=0;
        }
    }
  return maxlen;
}
```
