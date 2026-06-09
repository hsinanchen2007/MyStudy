### 解题思路
此处撰写解题思路
假设前面n个数已经得到一个最大预约时间res，写为f(n) = res,这时有两种情况，
1.这个最大预约时间有最后一个数，则需要判断f(n-1) + nums[n+1] 与f(n)的大小
2.这个最大预约时间没有最后一个数，则f(n+1) = f(n) + nums[n+1]

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        int res = 0;
        int lastRes = 0;
        boolean isBord = false;
        int i = 0;
        int len = nums.length;
        while (i < len) {
            if (isBord) {
                if (lastRes + nums[i] > res) {
                    int tmp = res;
                    res = lastRes + nums[i];
                    lastRes = tmp;
                    isBord = true;
                } else {
                    isBord = false;
                }
            } else {
                lastRes = res;
                res += nums[i];
                isBord = true;
            }
            i++;
        }
        return res;
    }
}
```