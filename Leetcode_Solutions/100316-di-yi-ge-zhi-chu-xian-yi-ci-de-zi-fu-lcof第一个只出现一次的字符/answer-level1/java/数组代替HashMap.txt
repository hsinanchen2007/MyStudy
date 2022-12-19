### 解题思路
这类问题很多，对于字符串，能用哈希表解决就可以用数组解决

### 代码

```java
class Solution {
     public char firstUniqChar(String s) {
        int[] arr = new int[26];
        for (int i = 0; i < s.length(); i++) {
           arr[s.charAt(i) - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (arr[s.charAt(i)-'a'] == 1) {
                return s.charAt(i);
            }
        }
        return ' ';
    }
}
```