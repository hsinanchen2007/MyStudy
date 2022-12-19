```
bool wordPattern(char * pattern, char * str){
    if(strcmp(str,"")==0||strcmp(pattern,"")==NULL)
        return 0;
    char **pat=(char**)malloc(sizeof(char*)*26);
    int i,len=0,patIndex=0;
    int strlen1=strlen(str);
    int strlen2=strlen(pattern);
    char *p=str,*q;
    for(i=0;i<26;i++)
        pat[i]=NULL;
    i=0;
    q=p;
    while(i<strlen1){
        len=0;
        while(*p!=' '&&i<strlen1){
            len++;
            p++;
            i++;
        }   
        char *tmpstr=(char*)malloc(sizeof(char)*(len+1));
        strncpy(tmpstr,q,len);
        
        tmpstr[len]='\0';
        if(pat[pattern[patIndex]-'a']==NULL){
            for(int j=0;j<26;j++){
                if(j==pattern[patIndex]-'a')
                    continue;
                else{
                    if(pat[j]){
                        if(strcmp(tmpstr,pat[j])==0)
                            return 0;
                    }
                    
                }
            }
            pat[pattern[patIndex]-'a']=tmpstr;
        }
            
        else{
            //printf("%s,%s\n",tmpstr,pat[pattern[patIndex]-'a']);
            if(strcmp(tmpstr,pat[pattern[patIndex]-'a'])!=0)
                return 0;
        }
        patIndex++;
        q=++p;
        i++;
        
    }
    if(patIndex<strlen2)
        return 0;

    return 1;
}
```
