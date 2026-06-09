### 解题思路
左右双指针遍历字符串，非元音字母跳过；左右都是元音字母则交换。
    注意：
        1. String不可修改，故用StringBuilder。
        2. 识别出隐藏的“坑”，比如这里题目没说大小写，我们要考虑全面。

### 代码

```java
class Solution {
    public String reverseVowels(String s) {
        StringBuilder sb = new StringBuilder(s);    // 因String无法修改，转化为StringBuilder
        int left = 0;
        int right = s.length() - 1;
        // 使用HashSet构建元音字母大小写参照表
        HashSet<Character> vowels = new HashSet<Character>();
        vowels.add('A');
        vowels.add('E');
        vowels.add('I');
        vowels.add('O');
        vowels.add('U');
        vowels.add('a');
        vowels.add('e');
        vowels.add('i');
        vowels.add('o');
        vowels.add('u');
        // 交换过程
        while (left < right) {
            // 跳过不为元音的字母
            while ((left < right) && (!vowels.contains(sb.charAt(left)))) {
                left++;
            }
            while ((left < right) && (!vowels.contains(sb.charAt(right)))) {
                right--;
            }
            // 开始交换当前左右元音字母
            char temp = sb.charAt(left);
            sb.setCharAt(left, sb.charAt(right));
            sb.setCharAt(right, temp);
            left++;
            right--;
        }
        return sb.toString();
    }
}
```