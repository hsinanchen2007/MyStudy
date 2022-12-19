

bool detectCapitalUse(char * s){
    int len=strlen(s);
    int i=0;
    int COUNT=0;
    for(i=0;i<len;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            COUNT++;
        }
        
    }
    if(s[0]>='a'&&s[0]<='z'){
        if(COUNT>0){
            return false;
        }
        else{
            return true;
        }
    }
    else{
        if(COUNT==len||COUNT==1){
            return true;
        }
        else{
            return false;
        }
    }
}



