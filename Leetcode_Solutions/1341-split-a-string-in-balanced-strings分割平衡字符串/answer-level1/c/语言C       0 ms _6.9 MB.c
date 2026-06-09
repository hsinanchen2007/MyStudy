int balancedStringSplit(char * s){
    int n=0;
    int i=0;
    int state=0;
    while(*(s+i)){
        if(*(s+i) == 'R') state++;
        if(*(s+i) == 'L') state--;
        if(!state) n++;
        i++;
    }
    return n;
}