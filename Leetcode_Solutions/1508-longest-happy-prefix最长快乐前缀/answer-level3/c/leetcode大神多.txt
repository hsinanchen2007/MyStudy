### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/ceb3adfc9aa8e566082f2f37ceb4b6feb9f5a90f43c8affdc2dd2e68e5e9fd38-image.png)

### 代码

```c
char * longestPrefix(char * s){
    int i;
    int l = strlen(s);

    for (i = l - 1; i > 0; i--) {
        if (!memcmp(s, s + l - i, i)) {
            break;
        }
    }

    char *res = calloc(i + 1, sizeof(char));
    memcpy(res, s, i);
    return res;
}
```