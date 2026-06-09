int countSegments(char * s){
    
    int sum=0;
    int k;
    int len;

    len = strlen(s);

    for(k=0; k<len; k++) {
        if(s[k]!=' ') {
            k++;
            while(s[k]!='\0'&&s[k]!=' ') {
                k++;
            }
            sum++;
        }
    }

    return sum;
}