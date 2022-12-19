执行用时: 16 ms, 在所有 java 提交中击败了 100.00% 的用户
内存消耗: 37.5 MB, 在所有 java 提交中击败了 100.00% 的用户

基本思路：
1. 统计每个每种字符出现的次数
2. 不断的滑动窗口，不断的更新窗口外每种字符出现的次数
3. 只要窗口外每种字符的数目小于等于n/4即可

```Java
public int balancedString(String s) {
        // 统计每个单词的数目
        int[] count = new int[26];
        int n = s.length();
        for (int i = 0; i < n; i++) {
            count[s.charAt(i)-'A']++;
        }
        int left = 0, right = 0;
        int ret = n;
        for (right = 0; right < n; right++) {
            count[s.charAt(right)-'A']--;
            // 注意此处 left是小于 n（而不是小于right）;因为窗口最小可以为0，这个时候left是大于right的
            while (left < n && count['Q'-'A'] <= n/4 && count['W'-'A'] <= n/4 && count['E'-'A'] <= n/4 && count['R'-'A'] <= n/4) {
                ret = Math.min(ret, right-left+1);
                count[s.charAt(left)-'A']++;
                left++;
            }
        }
        return ret;
    }
```
这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！