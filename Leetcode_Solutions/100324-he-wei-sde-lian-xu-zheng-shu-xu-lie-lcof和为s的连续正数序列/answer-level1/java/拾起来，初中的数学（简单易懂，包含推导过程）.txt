因为 题目 规定为：**连续正整数序列**，所以我们很好通过 等差数列的推导出：
```
n (n1 + nb(序列最后的数))
-----------------------  = target
2
```
我们可以简单推导一下(**连续正整数序列**:nb = n1 + n - 1)：
```
n (n1 + n1 + n - 1)
-----------------------  = target
2
```
化简n1
```
1:
n (n1 + n1 + n - 1) = 2 * target

2:
                    2 * target
2 * n1 + n - 1 =    -----------
                        n

3:
            2 * target
2 * n1  =  ----------- - （n - 1)
                n

4:
            1    2 * target
    n1  =  --- ( ----------- - （n - 1))
            2        n

5:
            1    2 * target - n * n - n
    n1  =  --- ( --------------------------)
            2        n

6:
                2 * target - n * n - n
    n1  =  -----------------------------
                    2 * n

7: n1 需要确保为正整数，否则 n1 不应该列举为我们的候选数
```

```
class Solution {
    public int[][] findContinuousSequence(int target) {
        int n = 2;
        int limit = target >> 1;
        LinkedList<int []> result = new LinkedList<>();
        int index = limit - 3;
        while (true) {
            int numerator = 2 * target - n * n + n;
            int denominator = 2 * n;
            // 如果不是整除，我们需要略过。
            if (numerator % denominator != 0) {
                n++;
                continue;
            }
            int n1 =  numerator / denominator;
            // n 如果大于于中间的数，等差数列公式可以明显看到，得到的结果会大于target值； n1 不能为0，因为题目说明需要正整数；
            if (n >= limit || n1 <= 0) {
                break;
            }
            int[] a = new int[n];
            for (int k = n1, i = 0; i < n; i++, k++) {
                a[i] = k;
            }
            result.addFirst(a);
            index--;
            n++;
        }
        return result.toArray(new int[result.size()][]);
    }
}
```
