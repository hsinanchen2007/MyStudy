### 解题思路

### 代码
字符串拆分成字符数组,比较字符对应的ASCII值总和
```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        char[] chars1 = s1.toCharArray();
        char[] chars2 = s2.toCharArray();
        if (chars1.length != chars2.length) {
            return false;
        }
        byte count = 0;
        for (char c : chars1) {
            count += (byte) c;
        }
        byte count1 = 0;
        for (char b : chars2) {
            count1 += (byte) b;
        }
        return count == count1;
    }
}
```