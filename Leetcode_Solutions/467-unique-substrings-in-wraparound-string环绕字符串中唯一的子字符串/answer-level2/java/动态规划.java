![捕获.PNG](https://pic.leetcode-cn.com/3f31cd765b656cb63a9d1ee632ea50cc6957eaae03adc922d222cad28d2cc19d-%E6%8D%95%E8%8E%B7.PNG)
解释：dp表示以当前字符结尾的最长递增子串的长度，map数组里存的是当前状态以a-z字母结尾的最长子串长度。每访问一个字符，则首先更新dp值，连续的则dp+1， 否则dp等于1。然后将dp值与map里对应的值比较，大于的话说明有新的以当前字母结尾的子串，更新sum的值。
```
class Solution {
    public int findSubstringInWraproundString(String p) {
        int len = p.length();
        if (len == 0) return 0;
        int[] map = new int[26];
        int dp = 0;
        int sum = 0;
        char[] arr = p.toCharArray();
        for (int i=0; i<len; i++) {
            char c = arr[i];
            if (i == 0 || (c-arr[i-1] -1)%26 == 0) {
                dp++;
            } else dp = 1;
            int cnt = map[c-'a'];
            if (dp > cnt) {
                sum += dp - cnt;
                map[c-'a'] = dp;
            }
        }
        return sum;
    }
}
```
