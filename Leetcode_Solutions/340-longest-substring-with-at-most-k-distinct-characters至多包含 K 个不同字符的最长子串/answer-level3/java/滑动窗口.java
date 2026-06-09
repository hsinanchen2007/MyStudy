和题目 [159. 至多包含两个不同字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-most-two-distinct-characters/solution/hua-dong-chuang-kou-by-tangweiqun-5/) 解法是一样的，区别就是将 k 替换成 2
```java
class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        // 存储至多包含 K 个不同字符的最长子串的长度
        int ans = 0;

        // 用于存储窗口中不同字符及其最大的索引
        Map<Character, Integer> map = new HashMap<>();

        int left = 0;
        int right = 0;
        while (right < s.length()) {
            char c = s.charAt(right);
            // 保证窗口中最多有 k 个不同的字符
            if (map.size() < k + 1) {
                map.put(c, right);
            }
            
            // left 指针移动
            // 移动时机：当窗口中出现了 k + 1 个不同的字符的时候
            // 移动策略：从窗口中删除索引最小的字符，将 left 设置为该索引的后面一位
            if (map.size() == k + 1) {
                // 拿到窗口中最小的索引
                // 注意最小的索引值不一定等于 left 值，
                // 比如字符串 eeeetf ，那么它的 left 值可能是 0，但是窗口的最小索引值可能是 3
                int delIndex = Collections.min(map.values());
                map.remove(s.charAt(delIndex));
                left = delIndex + 1;
            }

            // 计算最多包含 k 个不同字符的最长子串的长度
            ans = Math.max(ans, right - left + 1);
            // right 指针移动
            right++;
        }

        return ans;
    }
}
```