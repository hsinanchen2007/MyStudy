### 解题思路
分治法：就是把一个复杂的问题分成两个或更多的相同或相似的子问题，再把子问题分成更小的子问题……直到最后子问题可以简单的直接求解，原问题的解即子问题的解的合并。
此题可以理解为**x op y** ,以算数操作符为分隔符，可以把原问题分为:x和y两个子问题，而左右两个x和y又可以分别分为 **x1 op y1**，**x2 op y2**,以此类推，直到子部分只有一个数为止。

### 代码

```java
class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if (c == '-' || c == '+' || c == '*') {
                List<Integer> left = diffWaysToCompute(input.substring(0, i));
                List<Integer> right = diffWaysToCompute(input.substring(i + 1));
                for (int l : left) {
                    for (int r : right) {
                        switch (c) {
                            case '+' :
                                res.add(l + r);
                                break;
                            case '-' :
                                res.add(l - r);
                                break;
                            case '*' :
                                res.add(l * r);
                                break;
                        }
                    }
                }
            }
        }
        if (res.size() == 0) {
            res.add(Integer.valueOf(input));
        }
        return res;
    }
}
```