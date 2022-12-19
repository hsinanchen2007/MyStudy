### 解题思路
几次提交的执行时间都长的可怜，1500多ms，打败了5.26%。
不过内存总是打败100%。
额，还是希望时间短一点好。


### 代码

```c
char* compressString(char* S){
    int len = strlen(S);
    if(len < 3){
        return S;
    }

    int i, j;
    char* C = (char*)malloc(sizeof(char)*(2*len+1));
    memset(C, 0, sizeof(char)*(2*len+1));

    for(i=0, j=0; i<len; i++){
        if(S[i] != S[j]){
            sprintf(C, "%s%c%d",C,S[j],i-j);
            j = i;
        }
    }
    sprintf(C, "%s%c%d",C,S[j],i-j);

    if(strlen(C) < len){
        return C;
    }else{
        return S;
    }
}

```