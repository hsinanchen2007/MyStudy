### 解题思路
1. 此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/1db6e5f988a46e9a7bdabd93fd68c2772398052744410cc48274d08c490f033d-image.png)

### 代码

```c

char* reverseLeftWords(char* s, int n){
    int len = strlen(s);
    if (len < 1 || len > 10000) {
        return NULL;
    }
    char *res = (char*)malloc(sizeof(char) * 10001); //请你一定要记住char类型的要特妈的多申请一个字节。
     memset(res,  0, sizeof(char) * 10001);
   // if (ret != 0) {
    //    return NULL;
   // }
    int j = 0;
    for (int i = n; i < len; i++) {
        res[j++] = s[i]; 
    }
    for (int i = 0; i < n; i++) {
        res[j++] = s[i];
    }
    return res;
}
```