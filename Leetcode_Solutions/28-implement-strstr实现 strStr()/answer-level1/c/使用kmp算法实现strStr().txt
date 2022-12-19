### 解题思路
kmp算法中next 数组的构建基于有限状态机思想

### 代码

```c
//KMP算法

int **KMP(char *pat){
   int **dp;
   int n=strlen(pat);
   dp=(int **)malloc(sizeof(int *)*n);
   for(int i=0;i<n;i++){
      dp[i]=(int *)calloc(256,sizeof(int));
   }
   int X=0;
   dp[0][pat[0]]=1;
   for(int j=1;j<n;j++){
       for(int c=0;c<256;c++)
         dp[j][c]=dp[X][c];
        dp[j][pat[j]]=j+1;
        X=dp[X][pat[j]];
   }
   return dp;
}


int strStr(char * haystack, char * needle){
     int m=strlen(haystack),n=strlen(needle);
     if(n==0) return 0;
     int **dp=KMP(needle);
     int j=0,i=0;
     while(i<m&&j<n){
         
         if(needle[j]==haystack[i]){
             j++;
             i++;
         }
         else{
             j=dp[j][haystack[i]];
             i++;
         }
        if(j==n) return i-n;
     }
     return -1;
}
```