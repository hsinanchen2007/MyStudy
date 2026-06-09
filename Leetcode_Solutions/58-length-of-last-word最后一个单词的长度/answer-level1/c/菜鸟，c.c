
```
int lengthOfLastWord(char * s){
    int k = 0;
    int len = strlen(s);
    int output = 0;
    for (int i = 0; i < len; i++){
        if (s[i] != ' '){
            k++;
            output = k;
        }else{          
            k = 0;
        }
    }
    return  output;
}
```
