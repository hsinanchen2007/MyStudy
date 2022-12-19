### 解题思路
进制转换问题

### 代码

```c
int titleToNumber(char * s){
    int result=0;
    while(*s!='\0')
    {
        result=result*26+(*s-'A'+1);    
        ++s;    
    }
    return result;
}
```