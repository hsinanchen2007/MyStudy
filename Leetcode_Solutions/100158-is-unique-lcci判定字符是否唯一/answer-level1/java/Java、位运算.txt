### 解题思路
用 n 累积标记每个字符的出现情况。遍历字符串，对于每个字符，将对应的位置 1，然后与 n 异或，如果结果比 n 小，说明原来 n 中这一位也是 1，也就是这个字符已经出现过

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        int n = 0;
        for (char c : astr.toCharArray()) {
            int t = 1;
            t <<= (c - 'a');
            if ((n ^ t) < n) {
                return false;
            } else {
                n ^= t;
            }
        }
        return true;
    }
}
```