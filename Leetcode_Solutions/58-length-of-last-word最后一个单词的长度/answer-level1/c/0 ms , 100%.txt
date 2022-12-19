直接扫描一遍过， O(N)
```c
int lengthOfLastWord(char * str){
    char *s = str;

    int lastL  = 0;
    int length = 0;

    while(*s) {
        if (*s == ' ') {
            lastL  = length? length:lastL;
            length = 0;
        } else {
            length ++;
        }
        s++;
    }
    
    return length? length: lastL; 
}
```
