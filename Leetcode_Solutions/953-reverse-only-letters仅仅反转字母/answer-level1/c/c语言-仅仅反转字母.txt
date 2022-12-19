### 解题思路
和快排的思路类似

### 代码

```c
int apl(char *S,int n){
    if(S[n]>='a'&&S[n]<='z')return 1;
    else if(S[n]>='A'&&S[n]<='Z')return 1;
    else return 0;
}

char * reverseOnlyLetters(char * S){
        int i=0,j=strlen(S)-1;
        while(i<=j){
            while(i<strlen(S)&&apl(S,i)==0)i++;
            while(j>=0&&apl(S,j)==0)j--;
            if(i<=j){
                char temp=S[i];
                S[i]=S[j];
                S[j]=temp;
                i++;
                j--;
            }
        }
        return S;
}
```