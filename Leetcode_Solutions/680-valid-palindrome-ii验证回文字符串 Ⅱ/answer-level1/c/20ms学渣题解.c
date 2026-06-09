```
bool ss(char* s,int i,int j){
    while(i<j){
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
bool validPalindrome(char * s){
    int n=strlen(s);
    int i=0,j=n-1;
    while(i<j){
        if(s[i]!=s[j])
            return (ss(s,i+1,j)||ss(s,i,j-1));
        i++;
        j--;
    }
    return true;
}
```
