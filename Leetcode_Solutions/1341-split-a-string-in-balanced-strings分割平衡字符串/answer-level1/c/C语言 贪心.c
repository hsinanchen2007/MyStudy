int balancedStringSplit(char * s){
    int i = 0;
    int num = 0;
    int res = 0;
    while(s[i] != '\0'){
        if(s[i] == 'R'){
            num++;
        }
        else{
            num--;
        }
        if(num == 0){
            res++;
        }
        i++;
    }
    return res;
}