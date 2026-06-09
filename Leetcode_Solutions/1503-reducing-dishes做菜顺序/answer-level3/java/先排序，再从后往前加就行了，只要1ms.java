
先将满意度排序，如排序为[-9, -8, -1, 0, 5]，这时肯定是满意度高的优先给大的乘数。

乘数必然是差值为1的等差数列，比如
-1 * 1 + 0 * 2 + 5 * 3
可以分解为
(-1 + 0 + 5) + (0 + 5) + 5

是不是很清晰了，代码直接从5开始，从后面往前加

用公式表示，可以写成这样`f(i - 1) = f(i) + sum(i-1, i, ..., length - 1)`

编码如下（时间1ms）：
```java
class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        
        int val = 0;
        int sum = 0;
        for (int i = satisfaction.length - 1; i >= 0; i--) {
            sum += satisfaction[i];
            if (sum <= 0) {
                break;
            }
            val += sum;
        }
        
        return val;
    }
}
```