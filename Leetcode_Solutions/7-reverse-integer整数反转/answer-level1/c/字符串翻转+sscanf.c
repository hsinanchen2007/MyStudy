```
#define MAX_LEN 1024

void reverseString(char* s, int sSize){
    for (int i=0, j=sSize-1; i<j;i++,j--)
    {
        s[i] = s[i] ^ s[j];
        s[j] = s[j] ^ s[i];
        s[i] = s[i] ^ s[j];

    }
}

int reverse(int x) {
    long long ret;
    char xStr[MAX_LEN] = {0};
    
    sprintf(xStr, "%d", x);
    int len = strlen(xStr);
    if (xStr[0] == '-'){
        reverseString(xStr+1, len-1);  
    } else {
        reverseString(xStr, len);
    }

    sscanf(xStr, "%ld", &ret);

    if (ret < INT_MIN || ret > INT_MAX) {
        ret = 0;
    } 
    
    return (int)ret;
}

```
