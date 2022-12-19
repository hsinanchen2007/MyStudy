### 解题思路
此处撰写解题思路

### 代码

```java
/**
这道题比较烦人的是求和以后可能不等于 target ，所以让我们求“最接近的方案”。而这个烦人的根源是 value 的取值一定得是整数。正是因为题目说 value 是整数，并且“答案不一定是 arr 中的数字”，因此可以使用二分查找法确定这个整数值。
如果选择一个阈值 value ，使得它对应的 sum 是第 1 个大于等于 target 的，那么目标值可能在 value 也可能在 value - 1。
*/
class Solution {
    public int findBestValue(int[] arr, int target) {
        int max = 0;
        for (int a : arr) {
            max = Math.max(max, a);
        }
        int left = 1;
        int right = max;

        while (left < right) {
            int mid = (left + right) >>> 1;
            //sum随着mid的增大而增大，减小而减小
            int sum = getSum(arr, mid);
            //sum取小了说明mid取小了，下一个区间是[mid + 1, right]
            if (sum < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        //以上得到了sum >= target时最小的value，现在将其与value-1时的sum比较哪个更接近
        // 比较阈值线分别定在 left - 1 和 left 的时候与 target 的接近程度
        int sum1 = getSum(arr, left);
        int sum2 = getSum(arr, left-1);
        return (Math.abs(target-sum1) < Math.abs(target-sum2)) ? left : left-1;
    }

    private int getSum(int[] arr, int mid) {
        int sum = 0;
        for (int a : arr) {
            sum += (a > mid ? mid : a);
        }
        return sum;
    }
} 
```