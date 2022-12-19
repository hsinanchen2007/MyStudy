创建变量i和j，分别从头和尾向中间遍历，当S[i]和S[j]同时为字母时交换，否则就照搬。
```c
char * reverseOnlyLetters(char * S){
    int length=0,i,j;
    while(S[length]!=0) length++;
    char str[length+1];
    str[length]=0;
    i=0;
    j=length-1;
    while(i<=j){
        if(!(S[i]>='A'&&S[i]<='Z'||S[i]>='a'&&S[i]<='z')){
            str[i]=S[i];
            i++;
            continue;
        }
        if(!(S[j]>='A'&&S[j]<='Z'||S[j]>='a'&&S[j]<='z')){
            str[j]=S[j];
            j--;
            continue;
        }
        str[i]=S[j];
        str[j]=S[i];
        i++;
        j--;
    }
    S=str;
    return S;
}
```