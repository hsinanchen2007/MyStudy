### 解题思路
借助 memcmp 暴力破解。。。
![image.png](https://pic.leetcode-cn.com/4c36620fb9de2d1085bbe589a753815bdf4235299fe65948207aa95795d68cd7-image.png)

### 代码

```c
char * longestPrefix(char * s){
    int i;
    int len = strlen(s);
    for(i=len-1; i>0; i--){
        if(!memcmp(s, s + len - i , i)) break;
    }
    printf("%d",i);
    s[i] = '\0';
    return s;
}
```