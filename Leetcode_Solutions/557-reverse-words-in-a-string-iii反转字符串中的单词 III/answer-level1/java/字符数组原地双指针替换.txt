### 解题思路
参考代码注释
### 代码

```java
class Solution {
    // 该方法使用字符数组遇到空格则对前面的单词进行「双指针首尾替换」
    // 也可直接使用 indexOf 方法定位每个空格的位置后进行「双指针首尾替换」
    public String reverseWords(String s) {
        int m = 0;
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == ' ') { // 遇到空格替换空格前的单词
                this.swap(m, i - 1, chars);
                m = i + 1;
            }
        }
        this.swap(m, chars.length - 1, chars); // 最后一个单词替换
        return new String(chars);
    }
    // 双指针替换
    private void swap(int m, int n, char[] chars) {
        while (m < n) {
            char left = chars[m];
            chars[m] = chars[n];
            chars[n] = left;
            m++;
            n--;
        }
    }
}
```