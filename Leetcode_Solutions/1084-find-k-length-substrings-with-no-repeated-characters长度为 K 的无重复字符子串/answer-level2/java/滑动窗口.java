```java
class Solution {
    public int numKLenSubstrNoRepeats(String S, int K) {
       int len = S.length();
       if (len < K) return 0;

        int ans = 0;
        // 用于存储窗口中每个字符出现的次数
        int[] count = new int[26];

        // 维护滑动窗口
        int left = 0;
        int right = 0;
        while (right < len) {
            // 对 right 下的字符做计数
            int rightIndex = S.charAt(right) - 'a';
            count[rightIndex]++;

            // left 指针移动
            // 移动时机：right 指向的字符在当前窗口重复出现了
            // 移动策略：left 指向的字符从当前窗口中移除
            while (count[rightIndex] > 1) count[S.charAt(left++) - 'a']--;

            // 现在窗口中没有重复的字符了
            // 如果当前窗口的长度等于 K 的话，则找到了一个符合条件的子串
            if (right - left + 1 == K) {
                ans++;
                // 需要再次移动 left 指针，因为这里已经是符合的了，就要缩小窗口了
                count[S.charAt(left++) - 'a']--;
            }
            right++;
        }
        return ans;
    }
}
```