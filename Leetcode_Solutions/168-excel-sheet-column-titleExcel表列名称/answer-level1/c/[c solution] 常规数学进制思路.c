### 解题思路

4 war ！！！


### 代码

```c
char * convertToTitle(int n){
    if(n < 1){
        return NULL;
    }
    int temp = n , len = 0;
    while(temp > 0){
        temp = (temp - 1) / 26;
        len++;
    }
    char* ch = (char*)malloc(sizeof(char)* (len+1));
    ch[len] = '\0';
    while(len > 0){
        int tmp = (n - 1) % 26;
        ch[--len] = tmp + 'A';
        n = (n -1) / 26;
    }
    
    return ch;
}
```