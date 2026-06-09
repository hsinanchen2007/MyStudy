本题一种简单的思路就是搭配上双指针的滑动窗口，可以设置两个指针i，j，其中i指向j之前没有出现重复字符的第一个字符，j则指向当前被纳入考虑的字符。随后依次匹配s[i]，s[j]的值，直到s[i]==s[j] 或者 i==j
```
int lengthOfLongestSubstring(string s) {
    int n = s.length();
    if(n==0) return 0;
    if(n==1) return 1;
    vector<int> dp(n,1);
    int i=0,j=1;
    int Max=1;
    while(j<n){
        int fst_i = i;          //记录下此刻i指向的位置
        while (s[i]!=s[j] && i<j)
        {
            dp[j] += 1;
            i++;
        }
        if(i==j) i=fst_i;
        else i++;
        Max = max(Max, dp[j]);
        j++;
        if(n-i<=Max) break;     //如果后面的值考虑进来无法大于当前记录的最大值，直接中止
    }
    return Max;
}
```
