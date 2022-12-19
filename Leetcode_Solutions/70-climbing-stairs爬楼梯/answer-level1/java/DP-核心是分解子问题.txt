### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {

    //典型的，可以分解成子问题
    //n阶梯， 可由 f(n) = f(n-1) + f(n-2)
    //边界 f(1) = 1 f(2) = 2
    public int climbStairs(int n) {
        Map<Integer, Integer> resultMap = new HashMap<>();
        resultMap.put(1, 1);
        resultMap.put(2, 2);

        for (int i = 3; i <= n; i++) {
            resultMap.put(i, resultMap.get(i - 2) + resultMap.get(i - 1));
        }

        return resultMap.get(n);
    }
}
```