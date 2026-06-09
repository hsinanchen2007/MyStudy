### 解题思路
简单粗暴 

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void youxiu(char *str,int len,char *digits,int k,int digitsSize,char **returnstr,int *returnSize)
 {
    if(k==digitsSize)
    {
        returnstr[(*returnSize)]=(char *)calloc(digitsSize+1,sizeof(char));
        strcpy(returnstr[(*returnSize)++],str);
        return;
    }
    if(k>=digitsSize)
    return;
    char num_char[8][5] = {{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    int a=(int)(digits[k]-'2');
    int numlen=strlen(num_char[a]);
    for(int i=0;i<numlen;i++)
    {
        str[len]=num_char[a][i];
        youxiu(str,len+1,digits,k+1,digitsSize,returnstr,returnSize);
    }
 }

char ** letterCombinations(char * digits, int* returnSize){
    char **returnstr=(char**)malloc(sizeof(char *)*10000);
    *returnSize=0;
    int len=strlen(digits);
    if(len==0)
    return returnstr;
    char *str=(char *)calloc(len+1,sizeof(char));
    youxiu(str,0,digits,0,len,returnstr,returnSize);
    return returnstr;
}
```