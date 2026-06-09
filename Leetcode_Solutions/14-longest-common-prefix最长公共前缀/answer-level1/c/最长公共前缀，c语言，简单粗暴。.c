代码思想就是比较第一个和第二个字符串找出两者公共前缀，然后用两者的公共前缀和第三个字符串求出三者的公共前缀.....以此类推直到求出最后的结果,第一次提交0ms，稍微优化之后提交反而变成4ms了...后来发现同一段代码每次提交的结果都不一样，这是为什么？
```
//char**就是字符串的数组,strs[strsSize][]，而char[][]的长度用'\0'判断
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0){
        return "";
    }
    if(strsSize==1){
        return strs[0];
    }
    int n=strlen(strs[0]),j=0; 
    //n表示当前参与比较了的字符串的公共前缀长度，初始化为第一个串的长度，就可以避免第一次比较数组越界了，无需再判断。
    for(int i=1;i<strsSize;i++){
        j = 0;
        while(strs[0][j]==strs[i][j] && j<n){
            j++;
        }
        n = j;
    }
    char* result = (char*)malloc(sizeof(char)*(n+1));
    for(int k=0;k<n;k++){
        result[k] = strs[0][k];
    }
    result[n] = '\0';
    return result;
}
```
