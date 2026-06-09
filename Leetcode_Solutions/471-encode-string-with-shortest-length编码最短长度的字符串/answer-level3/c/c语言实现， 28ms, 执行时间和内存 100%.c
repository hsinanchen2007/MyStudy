c语言库函数缺乏，不能进行字符串加减。只能使用strcpy, strcat等操作。需要注意strncpy拷贝的后面要加上‘\0’
所以统一申请了一个size长度的字符串。

itoa 已经被c99取消，使用sprintf代替。

使用dp[i][j]数组存放 字符串矩阵的长度。避免每次都调用strlen. 否则会超时。

PS：计算过程需要注意 "aaa" 这种 要么在执行过程每次判断 转换后是否缩短。要么直接不用判断。但是，申请空间时要额外多申请几个字节。
避免被 “aaa” 转成 “3[a]” 后空间溢出。 这种类型在 判断大小时会被重新由 “a” "aa" 替换“3[a]” 回来，所以不需要额外的负责的判断。否则还需要
计算数字长度。
代码中偷懒，dp等写死长度，如果要优化，需要动态申请。

```

int  find_sub_size(char * s) {
    char * dst = (char *) malloc((strlen(s) * 2 + 1) *sizeof(char));    
    dst[0] = '\0';    
    int pos = 0;    
    strcat(dst,s);
    strcat(dst,s);
    pos = strstr(dst+1,s);
    return pos - (int)(dst); 
}

char * encode(char * s){
    int subsize = 0;
    int size = 0;
    
    size = strlen(s);
    int dp[200][200] = {0};
    
    char *** pps = (char *** ) malloc(sizeof(char **) * size);
    for(int i = 0; i < size; i++) {
        pps[i] = (char**) malloc(sizeof(char *) * size);
           for(int j = 0; j < size; j++) {
               pps[i][j] = malloc(sizeof(char) * size + 5);
               pps[i][j][0] = '\0';
           }        
    }
    
    for(int i = 0; i < size; i++) {
        strncpy(pps[i][i],&s[i],1); 
        dp[i][i] = 1;
        pps[i][i][1] = '\0';
    }
    
    for(int len = 2; len <= size; len++) {
        for(int i = 0; i + len <= size; i++) {
            int j = i + len - 1;            
             strncpy(pps[i][j],&s[i],len);
             dp[i][j] = len;
             pps[i][j][len] = '\0';            
             int subsize = find_sub_size(pps[i][j]);             
             int cursize = dp[i][j];//strlen(pps[i][j]);
             if(subsize < cursize) {                 
                 char lenstr[100] = {0};
                 int n = cursize/subsize;
                 sprintf(lenstr,"%d",n);
                 //itoa(n,lenstr,10);
                 strcpy(pps[i][j],lenstr);                 
                 strcat(pps[i][j],"[");                  
                 strcat(pps[i][j],pps[i][i + subsize - 1]);                        
                 strcat(pps[i][j],"]");                 
                 dp[i][j] = strlen(pps[i][j]);
             }
                 for(int k = i; k < j; k++) {
                     if(dp[i][k] + dp[k + 1][j] < dp[i][j]) {    
                         strcpy(pps[i][j],pps[i][k]);                         
                         strcat(pps[i][j],pps[k + 1][j]);  
                         dp[i][j] = dp[i][k] + dp[k + 1][j];
                     }
                 }            
           }
      }

      return pps[0][size - 1];      
}

```
