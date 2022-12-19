### 解题思路
该题的解决方法分为三步：
1 复制需要左旋的字符串
2 将不需要左旋的字符串移动到字符数组前端
3 将左旋字符串放到字符串末尾

### 代码

```c
char* reverseLeftWords(char* s, int n){
    char reverse[n];
    int i =0;
    //复制所需左旋的字符串
    for(i =0; i < n;i++)
    {
        reverse[i] = s[i];
    }
    //将不需旋转的字符串移动到字符数组前端
    for(i = n; i<strlen(s);i++)
    {
        s[i-n] = s[i];
    }
    //将左旋字符串放到字符串末尾
    for(i =0; i<n;i++)
    {
        s[i+strlen(s)-n] = reverse[i];
    }
    return s;
}
```