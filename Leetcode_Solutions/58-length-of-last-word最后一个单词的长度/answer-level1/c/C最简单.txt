int lengthOfLastWord(char * s){
    int n = 0;
    int i = 0;
    int flag = 0;
    while(s[i]!='\0'){
        if(s[i]!=' '){
            if(flag == 1){n =0;flag=0;};
            n++;
        }else{
            flag = 1;
           
        }
        i++;

    }
    return n;

}