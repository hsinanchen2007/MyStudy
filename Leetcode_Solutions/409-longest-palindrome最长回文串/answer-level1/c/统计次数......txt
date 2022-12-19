### 解题思路
1.统计s中每个字母出现次数
2.偶数次的字母可以全部选上。
3.奇数次字母只可一个全选，其他奇数次的需要-1
### 代码

```c
int longestPalindrome(char * s){
    if (!s) return 0;
    short cnt[52] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') cnt[s[i]-'a']++;
        if (s[i] >= 'A' && s[i] <= 'Z') cnt[s[i]-'A'+26]++;
    }

    int oddSel = 0;
    int ans = 0;
    for (int i = 0; i < 52; i++) {
        if (cnt[i] % 2 && oddSel != 1) {
            oddSel = 1;
            ans += cnt[i];
        } else if (cnt[i] % 2 && oddSel == 1) {
            ans += (cnt[i] - 1);
        } else {
            ans += cnt[i];
        }
    }
    return ans;
}
```