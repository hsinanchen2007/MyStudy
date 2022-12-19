### 解题思路


### 代码

```c
char * convertToBase7(int num){
    if(num==0)  return "0";
    int sign = 0, n = num, size = log10(num)+7;
    if(n < 0){
        size = log10(-num)+7;
        n = -n; 
        sign = 1;
    }   
    char* res = (char*)malloc(sizeof(char)*(size+1));
    res[size--] = '\0';
    while(n>0){
        int curr = n%7;
        res[size--] = curr+'0';
        n /= 7;
    }
    if(sign!=0)  res[size--] = '-';
    return res+size+1;
}
```