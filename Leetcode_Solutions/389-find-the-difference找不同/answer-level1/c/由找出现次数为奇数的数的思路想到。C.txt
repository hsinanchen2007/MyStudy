### 解题思路
把每个字符异或一遍，重复的就为0了，剩下一个单的
### 代码

```c
char findTheDifference(char * s, char * t){
    char result = 0;
    while((*s)!=0)
    {
        result ^= (*t)^(*s);
        s++;t++;
    }
    return result^(*(t));
}
```