### 解题思路
判断n是否是偶数还是奇数， 奇数 就是全a, 偶数就是第一个数为a, 剩下的数为b

### 代码

```c
char * generateTheString(int n){
    char* ans = (char*)malloc(sizeof(char) * (n + 1));
    ans[0] = 'a';
    if ((n & 1) == 0) {
        for (int i = 1; i < n; i++) {
            ans[i] = 'b';
        }
    }  else {
        for (int i = 1; i < n; i++) {
            ans[i] = 'a';
        }
    }
    ans[n] = '\0';
    return ans;
}

```