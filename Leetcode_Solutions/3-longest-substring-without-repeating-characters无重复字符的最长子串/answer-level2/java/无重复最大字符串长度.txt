### 解题思路
扫描字符串，每次当前的字符串和前面某个重复了，那么从那重复的地方开始重新计算不重复的字符串。
执行用时 : 3 ms 内存消耗 : 38.6 MB

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) {
                return 0;
            }
            if (s.length() == 1) {
                return 1;
            }
            int maxLength = 0;
            int index = 0;//标记重新开始计算不重复字符串的开始坐标
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                // tempIndex 为临时坐标，因为需要从重新开始计算的坐标到当前i，找到是否有与当前i坐标相同的字符
                int tempIndex = index;
                while (tempIndex < i && s.charAt(tempIndex) != c) {
                    //从开始计算的坐标到当前i坐标，不重复的话，tempIndex + 1
                    tempIndex++;
                }
                //tempIndex累加到了和i一样的值，说明从index到i这之间没有重复字符串。
                if (tempIndex != i) {
                    //tempIndex不为i的话，说明当前i坐标的字符和tempIndex值重复了
                    maxLength = Math.max((i - index), maxLength);//计算出和之前相比较大的长度值
                    //需要重新计数不含重复字符串坐标。
                    index = tempIndex + 1;
                }
                //若i到达字符串的末尾，判断一下，i到index之间的长度是否是最大的不重复串
                if (i == s.length() - 1) {
                    maxLength = Math.max((i - index + 1), maxLength);
                }
            }
            return maxLength;
    }
}
```