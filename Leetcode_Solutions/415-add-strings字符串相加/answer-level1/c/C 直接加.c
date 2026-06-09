```
char * addStrings(char * num1, char * num2){
    int l1 = strlen(num1);
    int l2 = strlen(num2);
    int l3 = l1 > l2 ? l1 : l2;
    char buf,flag=0;
    char *ret = malloc(sizeof(char) * (l3+2));
    int i,j,k;
    
    ret[l3+1]= '\0';
    
    for(i = l1-1, j = l2-1, k = l3; k > 0; i--, j--, k--) {
        
        if(i < 0)
        buf = num2[j] + flag-'0';
        else if(j < 0)
        buf = num1[i]  + flag-'0';
        else
        buf = num1[i] + num2[j] + flag -'0' * 2;
        
        
        ret[k] = buf % 10 + '0';
        flag = buf / 10 ? 1 : 0;
    }
 
 
    ret[k] = flag + '0';
 
    if(ret[k] == '0') {
         for( k = 0; k <=l3; k++) {
            ret[k] = ret[k+1];
         }
    }
    
    return ret;
}
```
