思路：
1、定义一个max记录过程中最大值
2、定义lSum、rSum从两头向中间推进的记录的两个最终子序和
3、到中间汇聚，再取最大值：Math.max(max, lSum+rSum);

```
public static int maxSubArray2(int[] nums) {
        int max = Math.max(nums[0],nums[nums.length-1]);//过程中最大值
        // 左半部分，最近一次子序和
        int lSum = 0;
        // 右半部分，最近一次子序和
        int rSum = 0;
        // 左边递增，右边递减
        for (int i = 0,j=nums.length-1; i <= j; i++,j--) {
            lSum = lSum>0?lSum+nums[i]:nums[i];
            max = Math.max(max,lSum);
            if (j!=i){
                rSum = rSum>0?rSum+nums[j]:nums[j];
                max = Math.max(max,rSum);
            }
        }
        // 汇聚
        return Math.max(
                max,//左右两边最大的
                lSum+rSum//中间聚合
        );
    }
```