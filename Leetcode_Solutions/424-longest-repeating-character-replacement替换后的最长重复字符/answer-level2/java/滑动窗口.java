```java
class Solution {
    public int characterReplacement(String s, int k) {
        // 存储最终的结果
        int ans = 0;

        // 定义窗口
        int left = 0;
        int right = 0;

        // 用于存储每个窗口中每个字符出现的次数
        int[] counts = new int[26];
        // 用于存储每个窗口中出现次数最多的字符的次数
        int maxCounts = 0;
        // 移动窗口
        while (right < s.length()) {
            // 计算当前窗口出现最多字符出现的次数
            char c = s.charAt(right);
            int index = c - 'A';
            counts[index]++;
            maxCounts = Math.max(maxCounts, counts[index]);

            // left 移动的时机：当前窗口大小减去最大次数大于 k 
            // 移动的策略：从当前窗口中减去 left 对应的字符
            while (right - left + 1 - maxCounts > k) {
                c = s.charAt(left);
                counts[c - 'A']--;
                left++;
            }
            // 计算当前窗口长度为当前窗口最长重复字符
            ans = Math.max(ans, right - left + 1);

            right++;
        }

        return ans;
    }
}
```