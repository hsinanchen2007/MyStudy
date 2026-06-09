### 解题思路
代码思路：只需要判断当前字符与前一个字符的关系
两个单括号组成的情况有四种:'((', '))', '()', ')('
前两种情况，这两个单括号肯定不能在同一子序列中，因为那样会加深字符串深度，所以分别分到A，B组
后两种情况，分到同一组不会加深字符串深度，所以可以分到同一组
### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int[] result = new int[seq.length()];
        for (int i = 1; i < seq.length(); i++) {
            if (seq.charAt(i - 1) == seq.charAt(i)) {
                result[i] = 1 - result[i - 1];
            } else {
                result[i] = result[i - 1];
            }
        }

        return result;
    }
}
```