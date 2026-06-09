int lengthOfLastWord(char * s){
    
    int len=strlen(s);
    if(len==0) return 0;
    int i=len-1;
    while(i>=0&&s[i]==' ') i--;         
    len=i;
    while(i>=0&&s[i]!=' ') i--;                                  
    return len-i;
}

欢迎批评