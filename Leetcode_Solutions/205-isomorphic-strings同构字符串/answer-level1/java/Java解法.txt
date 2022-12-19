执行用时 :9 ms, 在所有 Java 提交中击败了67.50%的用户
内存消耗 :36.3 MB, 在所有 Java 提交中击败了97.24%的用户

### 解题思路
利用ASCII码和数组模拟一个Map，将两个字符串的pattern同字符串表示出来，最后看两个pattern一不一样。

### 代码

```java
class Solution {
    public boolean isIsomorphic(String s, String t) {
        int[] likeMap1 = new int[128];
        int count = 1;
        StringBuilder pattern1 = new StringBuilder();
        StringBuilder pattern2 = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (likeMap1[s.charAt(i)] == 0) {
                likeMap1[s.charAt(i)] = count;
                pattern1.append(count);
                count++;
            } else {
                pattern1.append(likeMap1[s.charAt(i)]);
            }
        }
        count = 1;
        int[] likeMap2 = new int[128];
        for (int i = 0; i < t.length(); i++) {
            if (likeMap2[t.charAt(i)] == 0) {
                likeMap2[t.charAt(i)] = count;
                pattern2.append(count);
                count++;
            } else {
                pattern2.append(likeMap2[t.charAt(i)]);
            }
        }
        return pattern1.toString().equals(pattern2.toString());
    }
}
```