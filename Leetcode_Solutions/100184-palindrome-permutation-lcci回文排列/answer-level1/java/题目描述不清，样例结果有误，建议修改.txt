### 解题思路
注意：不忽略大小写！输入范围不只是字母，包括其他符号！

### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
        char[] chars = s.toCharArray();
        int[] letterCounts = new int[128];
        for (char ch : chars) {
            letterCounts[ch]++;
        }
        int count = 0;
        for (int letterCount : letterCounts) {
            if (letterCount % 2 == 1) {
                count++;
            }
        }
        return count <= 1;
    }
}
```