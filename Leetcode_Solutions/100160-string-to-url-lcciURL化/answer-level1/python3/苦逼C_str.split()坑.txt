### 解题思路
最大3 * length + 1，申请就行，常规操作。

### 代码一、申请额外内存
```c
char* replaceSpaces(char* S, int length){
    char *ans = (char *)malloc(sizeof(char) * (3 * length + 1));
    int i, j;
    for (i = 0, j = 0; i < length; i++) {
        if (S[i] == ' ') {
            ans[j++] = '%';
            ans[j++] = '2';
            ans[j++] = '0';
        } else ans[j++] = S[i];
    }
    ans[j] = '\0';
    return ans;
}
```
### 代码二、原地修改
```c
char* replaceSpaces(char* S, int length){
    int i, spaceNums = 0;
    // 1.数空格
    for (i = 0; i < length ; i++) {
        if (S[i] == ' ') spaceNums++;
    }
    // 2.处理末尾:由于空格占一个长度，即抵消%，20就是多的两个长度
    int last_idx = length + spaceNums * 2 - 1;
    S[last_idx+1] = '\0';  // 长度截断
    // 3.元素右移，遇到空格填%20:因此必须从最后开始避免覆盖
    for (i = length - 1; i >= 0; i--) {
        if (S[i] == ' ') {  // 注意反向！
            S[last_idx--] = '0';
            S[last_idx--] = '2';
            S[last_idx--] = '%';
        } else S[last_idx--] = S[i];
    }
    return S;
}
```


python中的str.split()默认不加参数，连续切割产生的空串是会被消掉的，只有自己加入参数`" "`才有空串。

```python []
class Solution:
    def replaceSpaces(self, S: str, length: int) -> str:
        return '%20'.join(S[:length].split(' '))  # 巨坑，不能直接split()
```

还有replace大法，同样切片产生新的字符串。
```python3 []
class Solution:
    def replaceSpaces(self, S: str, length: int) -> str:
        return S[:length].replace(' ', '%20')
```