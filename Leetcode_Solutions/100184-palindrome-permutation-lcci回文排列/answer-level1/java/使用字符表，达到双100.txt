### 解题思路
思路见代码注释

### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
        // 当字符串长度为奇数时，允许一个字符出现奇数次，否则不循序出现奇数次的字符
        int flag = s.length() % 2 == 1 ? 1 : 0;

        // 用于存储字符出现次数的表
        int[] table = new int[256];
        // 遍历字符串，记录所有字符出现次数
        for (int i = 0; i < s.length(); i++) {
            table[s.charAt(i)]++;
        }
        // 遍历表，判断字符串是否可组成回文串
        for (int i = 0; i < 256; i++) {
            if (table[i] % 2 == 1){
                if (flag == 0) return false;
                flag -= 1;
            }
        }
        return true;
    }
}
```