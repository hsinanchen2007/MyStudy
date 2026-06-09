### 解题思路
此处撰写解题思路

### 代码

```c
int titleToNumber(char * s){
    int i = 0;
    int sum = 0;
    int base = 26;
    
    while(s[i] != '\0') {
        sum = (s[i] - 'A' + 1) + sum * base;
        i++; 
    }

    return sum;
}
```