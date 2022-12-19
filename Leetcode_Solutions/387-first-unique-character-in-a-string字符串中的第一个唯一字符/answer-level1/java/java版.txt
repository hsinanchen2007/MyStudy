### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int firstUniqChar(String s) {
        if(s == null) {
            return -1;
        }
        int[] flag = new int[26];
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            flag[c - 'a']++;
        }
        for(int i = 0; i < s.length(); i++) {
            if(flag[s.charAt(i) - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
}
```