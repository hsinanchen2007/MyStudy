
 ![image.png](https://pic.leetcode-cn.com/d2ccfb3f6494a703de0afb422bfa8049bfdb9a9fabc338e5a51bae81710cacd7-image.png)
递归：
![image.png](https://pic.leetcode-cn.com/55480b9d479cd89f6db7b0795c29adc9be11fe1e2e366055bcd9b4238010bde8-image.png)


# 代码：
第一种方法：
```

char ** letterCasePermutation(char * S, int* returnSize){
    int count = 0, stringlen = strlen(S) + 1,currenlen = 1,j = 0;
    
    for(char* copyS = S;*copyS != '\0';copyS++){
        count+= (isalpha(*copyS) > 0);
    }
    *returnSize = (int)pow(2.0,(double)count);

    char **ans = malloc(sizeof(char*) * *returnSize);
    assert(ans !=  NULL);

    *ans = malloc(sizeof(char) * stringlen);
    memcpy(*ans, S,sizeof(char)*stringlen);
   
    j = 0;
    while(S[j] != '\0'){
        if(isalpha(S[j])){
            for(int i = 0; i < currenlen; i++){
                ans[currenlen + i]= malloc(sizeof(char)*stringlen);
                memcpy(ans[currenlen + i], ans[i],sizeof(char)*stringlen);
                ans[i][j] = tolower(S[j]);
                ans[currenlen + i][j] = toupper(S[j]);
            }
            currenlen *= 2;
        }
        j++;
    }

   
    return ans;
}

```
第二种方法（递归）
```
void recursionPermutaion(char ***ans, int* currlen, char *S, int index,char **prototype);

char ** letterCasePermutation(char * S, int* returnSize){
    int count = 0,currlen = 0;
    
    for(char* copyS = S;*copyS != '\0';copyS++){
        count+= (isalpha(*copyS) > 0);
    }
    *returnSize = (int)pow(2.0,(double)count);
    char **ans = malloc(sizeof(char*) * *returnSize),
        *prototype = malloc(sizeof(char) * (strlen(S) + 1));
    assert(ans !=  NULL && prototype !=NULL);

    prototype[strlen(S)] = '\0';
    recursionPermutaion(&ans, &currlen, S, 0,&prototype);
    return ans;
}

void recursionPermutaion(char ***ans, int* currlen, char *S, int index,char **prototype){
    if(S[index] == '\0'){
         (*ans)[(*currlen)]  = malloc(sizeof(char) * (index + 1));
         memcpy((*ans)[(*currlen)++],*prototype,sizeof(char)*(index + 1));
        return;
    }

   
    char *string = *prototype;
    if(isalpha(S[index])){
        string[index] = tolower(S[index]);
        recursionPermutaion(ans,currlen,S ,index + 1,prototype);
        string[index] = toupper(S[index]);
        recursionPermutaion(ans,currlen,S ,index + 1,prototype);
    }else{
        string[index] = S[index];
        recursionPermutaion(ans,currlen,S ,index + 1,prototype);
    }
    return;
}
```

