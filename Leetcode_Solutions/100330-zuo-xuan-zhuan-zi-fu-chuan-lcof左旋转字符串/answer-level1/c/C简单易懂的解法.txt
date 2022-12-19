
![image.png](https://pic.leetcode-cn.com/186a31a90cda750f92da2fb7578b8d4008c7c1ed058af8f9d8afb410600962e7-image.png)


# 代码：
```
char* reverseLeftWords(char* s, int n){
    int len = strlen(s),i = 0;;
    char *ans = malloc(sizeof(char) * (len + 1));
    while(i < len){
        *(ans++) = s[(n + i++)%len];
    }
    *ans= '\0';
    return ans - len;
}
```
