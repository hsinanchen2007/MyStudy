执行用时 : 0 ms, 在所有 C 提交中击败了 100.00% 的用户
内存消耗 : 6.7 MB, 在所有 C 提交中击败了 84.45% 的用户

```
int numJewelsInStones(char * J, char * S){
    char hash[58] = {0};  // 'z' - 'A' + 1

    for (int i = 0; i < 50; i++) {
        if (J[i] == '\0') {
            break;
        }
        hash[J[i] - 'A'] = J[i];
    }
    int ret = 0;
    for (int i = 0; i < 50; i++) {
        if (S[i] == '\0') {
            break;
        }
        if (hash[S[i] - 'A'] == S[i]) {
            ret++;
        }
    }

    return ret;
}
```