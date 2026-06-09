### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        int[] temp = new int[26];
        if (astr.length() > 26) return false;
        astr = astr.toLowerCase();
        int amount = astr.length();
        return isUnHelp(astr, temp, amount, 0);

    }

    public boolean isUnHelp(String astr, int[] temp, int length, int current) {
        if (current >= length) return true;
        if (temp[astr.charAt(current) % 26] == 0) {
            temp[astr.charAt(current) % 26] = 1;
            return isUnHelp(astr, temp, length, current + 1);
        } else {
            return false;
        }
    }
}
```