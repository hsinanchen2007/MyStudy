### 解题思路
通过阅读可以发现要保持两个子序列的平衡，也就是你分一个括号，我分一个括号

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int a = 0, b = 0;
        int[] res = new int[seq.length()];
        for (int i = 0; i < seq.length(); i++) {
            char c = seq.charAt(i);
            if (c == '(') {
                if (a > b) {
                    b++;
                    res[i] = 0;
                } else {
                    a++;
                    res[i] = 1;
                }
            } else {
                if (a > b) {
                    a--;
                    res[i] = 1;
                } else {
                    b--;
                    res[i] = 0;
                }
            }
        }
        return res; 
    }
}
```