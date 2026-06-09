### 解题思路
1. 常用ASCII码有128个，故建立128长度字符数组
2. 两个相同的字符异或为0
3. 若数组中不为0的个数大于1，则无法形成回文

### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
    char[] arr = new char[128];
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            arr[c] ^= c;
        }
        int num = 0;
        for (char c : arr) {
            if (c != 0) num++;
            if (num > 1) return false;
        }
        return true;
    }
}
```