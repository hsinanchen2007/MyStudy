### 解题思路
分别统计L 和 R的个数 当统计到的个数相等时则是一个平衡字符串

### 代码

```java
class Solution {
    public int balancedStringSplit(String s) {
        int count = 0;
        char[] array = s.toCharArray();
        int L = 0;
        int R = 0;
        for (int i = 0; i < array.length; ++i) {
            if (array[i] == 'L') {
                ++L;
            } else {
                ++R;
            }
            if (L == R) {
                ++count;
            }
        }
        return count;
    }
}
```