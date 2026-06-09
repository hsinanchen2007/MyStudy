### 解题思路
遍历s1，表统计字符出现次数，遍历s2，减少表字符出现次数，最后表内最大值为0，则字符相同

### 代码

```java
class Solution {
   
    public boolean CheckPermutation(String s1, String s2) {

        if (s1.length() != s2.length()) return false;
        int[] st = new int[256];

        for (int i = 0; i < s1.length(); i++) {
            st[s1.charAt(i)] += 1;
        }
        for (int i = 0; i < s2.length(); i++) {
            st[s2.charAt(i)] -= 1;
        }
        Arrays.sort(st);
        return st[255] == 0;
    }
}
```