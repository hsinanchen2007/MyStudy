双指针法实现，从字符串左边left开始,找到第一个不同的字符right.然后从这个字符开始往右找,找到第一个既不等于left位置
也不等于right位置的字符串temp,则此时最大字符串长度max等于temp-left,然后把right的位置赋给left.当left小于
字符串长度或者字符串长度减去left大于max的时候停止遍历,此时找到的max就是至多包含两个不同字符的最长子串.

代码如下:
```
class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        if (s == null || s.length() <= 2) {
            return s.length();
        }

        int left = 0, max = 0;
        while (left < s.length() && s.length() - left > max) {

            int tempLeft = left;
            while (left < s.length() && s.charAt(left) == s.charAt(tempLeft)) {
                left++;
            }
            int right = left;
            int tempRight = right;
            while (right < s.length() && (s.charAt(right) == s.charAt(tempRight) || s.charAt(right) == s.charAt(tempLeft))) {
                right++;
            }
            max = Math.max(max, right - tempLeft);
            left = tempRight;
        }

        return max;
    }
}
```
