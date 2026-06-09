执行用时 :5 ms, 在所有 Java 提交中击败了76.16%的用户
内存消耗 :36.9 MB, 在所有 Java 提交中击败了97.70%的用户

### 解题思路
利用ASCII码来储存出现字母的个数

### 代码

```java
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] charSequence = new int[26];
        for (int i = 0; i < magazine.length(); i++) {
            charSequence[magazine.charAt(i)-97]++;
        }
        for (int i = 0; i < ransomNote.length(); i++) {
            charSequence[ransomNote.charAt(i)-97]--;
        }
        for (int i = 0; i < 26; i++) {
            if (charSequence[i] < 0) return false;
        }
        return true;
    }
}
```