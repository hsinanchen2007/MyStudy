### 解题思路
因为只有A，B 两个集合，
第一个值固定放0(左括号, 放1同理)，
以后每次与前一次比较，如果括号方向相同，则存与上一次相反的值（比如上一次存0，那么这次就是1)，
如果与前一个值相反，则存相同的值

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int[] res = new int[seq.length()];
        char lastChar = '(';
        int lastVal = 0;

        char[] chars = seq.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (i == 0) {
                res[i] = 0;
                continue;
            }
            if (chars[i] == lastChar) {
                lastVal = 1 ^ lastVal;
            }
            res[i] = lastVal;
            lastChar = chars[i];
        }
        return res;
    }
}
```