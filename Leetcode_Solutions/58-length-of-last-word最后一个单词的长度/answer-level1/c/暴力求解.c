int lengthOfLastWord(char * s){
        int size=0;
    
    while(*s!='\0')
    {
        while(*s!=' '&&*s!='\0')
    {
        size++;
        s++;
    }
    if(*s!='\0')
    {
        while(*s==' ')
            s++;
    }
    else
        return size;
    if(*s=='\0')
        return size;
    else
        size=0;
    }
    return size;
}