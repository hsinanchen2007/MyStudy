### 解题思路
此处撰写解题思路

### 代码

```c
char * toHexspeak(char * num){
    char table[6] = {'A','B','C','D','E','F'};
    long long n = 0, size = strlen(num), index = size - 1;
    char*res = (char*)malloc(sizeof(char) * (size+1));
    for(int i = 0; i < size; i++) {
        n = n*10+num[i]-'0';
    }
    res[size] = '\0';
    while(n>0){
        int curr = n%16;
        if(curr>=2 && curr<=9){
            return "ERROR";
        }
        switch(curr){
            case 0: res[index--]='O'; break;
            case 1: res[index--]='I'; break;
            default:    res[index--]=table[curr%10]; break;
        }
        n /= 16;
    }
    return res+index+1;
}
```