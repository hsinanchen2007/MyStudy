### 解题思路
- 当 n = 2 时, 返回 1, 当 n = 3 时, 返回2;
- 当 n > 3 时, 若除以 3 后余数为 1 则将 3 和 1 换为 2 和 2， 解中最多包含两个 2，因此先计算 3 的数量，再计算 2 的数量；
- 得到 2 和 3 的数量后计算出结果并返回。

### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        /*
        int max = 0;
        for(int m = 2; m <= n / 2 || m == 2; m ++){
            int average = n / m;
            int remain = n % m;
            double product = Math.pow(average + 1, remain) * Math.pow(average, m - remain);
            if (product > max)
                max = (int)product;
        }
        return max;
        */
        int num_2 = 0, num_3 = 0;
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        num_3 = n / 3;
        int remain = n % 3;
        if(remain == 1){
            num_3--;
            remain += 3;
        }
        num_2 = remain / 2;
        double result = Math.pow(3, num_3) * Math.pow(2, num_2);
        return (int) result;
    }
}
```