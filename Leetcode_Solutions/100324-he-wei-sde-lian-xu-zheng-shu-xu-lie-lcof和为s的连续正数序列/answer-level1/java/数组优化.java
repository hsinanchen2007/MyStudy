### 解题思路
写一下用数组解决的时候怎么优化。
有数学规律，一个从1开始的连续的数要等于target，那么这些数字中最大的一个数字不能超过 **target/2 + 1**；
设 temp = target / 2;
那么， temp + (temp+1) = target +1;
一半以后的两位连续数字的和总会超过target, 不用检查，因此可以减小for循环的次数。
因为target的最大值为10^5, 计算的出，一个数组中的最多的元素不超过500，甚至更少，怎么得到的呢？
1 + 2 +3 + ... + 499 + 500 = 124750,大于 10^5， 这样可以减缩数组的数目，
用的就是暴力破解方法，很好理解。看代码就懂了。


### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        int[][] ans = new int[20][500];
        int len = (target / 2) + 1;
        int j = 0;
        int sum = 0;
        for (int i = 1; i <= len; i++) {
            int temp = i;
            sum = temp;
            while (target - sum > 0) {
                temp++;
                sum += temp;
            }
            if (target - sum == 0) {
                int begin = i;
                for (int k = 0; k <= temp - i; k++) {
                    ans[j][k] = begin;
                    begin++;
                }
                j++;
            } else if (target - sum < 0)
                continue;
        }
        int counter = 0;
        int[][] res = new int[j][];
        for (int i = 0; i < j; i++) {
            counter = 0;
            for (int k = 0; k < 500; k++) {
                if (ans[i][k] != 0) {
                    counter++;
                }
                if (ans[i][k] == 0) {
                    break;
                }
            }
            res[i] = new int[counter];
            for (int index = 0; index < counter; index++) {
                res[i][index] = ans[i][index];
            }
        }
        return res;
    }
}
```