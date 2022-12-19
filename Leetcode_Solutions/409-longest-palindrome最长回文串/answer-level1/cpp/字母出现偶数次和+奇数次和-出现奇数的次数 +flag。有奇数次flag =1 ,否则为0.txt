```
int longestPalindrome(string s) {
    int count[128] ={0};
    int num =0;
    int flag = 0;
    for (char c : s)
        count[c]++;
    for (int i = 0; i<128 ;i++) {
        num += count[i]/2*2;
        if (count[i]%2 == 1)
            flag = 1;
    }
    return num + flag;
}
```
字母出现偶数次和+奇数次和-出现奇数的次数 +flag。有奇数次flag =1 ,否则为0