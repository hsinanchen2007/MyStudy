### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] diStringMatch(String S) {
        int length = S.length();
        int begin = 0;
        int end = length;
        int[] results = new int[length + 1];
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == 'I') {
                results[i] = begin++;
            } else {
                results[i] = end--;
            }
        }
        results[length] = begin;
        return results;
    }
}
```