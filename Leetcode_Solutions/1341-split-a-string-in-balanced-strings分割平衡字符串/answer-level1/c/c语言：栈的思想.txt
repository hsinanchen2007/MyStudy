这道题，我运用了栈的思想
定义一个整数a，遇到'R'则加1，遇到'L'则减一，当a为0时，则res++；

int balancedStringSplit(char * s){
    int res=0;
    int a=0;
    for(int i =0;s[i]!='\0';i++){
        if(s[i]=='R') a++;
        if(s[i]=='L') a--;
        if(a==0) res++; 
    }
    return res;
}