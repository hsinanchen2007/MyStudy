### 解题思路
参考上一题的双指针法

### 代码

```java
class Solution {
    public static int threeSumClosest(int[] nums,int x) {
        Arrays.sort(nums); // 排序
        int sum;// 三数之和
        int res;// sum - x 的差值，与目标数的差值，用来判断是左下标移动还是右下标移动
        int abs;// res的绝对值，用来判断相似度
        int result = 0;// 最后返回的结果
        int most = Integer.MAX_VALUE;// 记录与目标值x的最小距离，初始化设为最大值
        for (int first = 0; first < nums.length - 2; first++) {
            // 去重
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // 左下标
            int second = first + 1;
            // 右下标
            int third = nums.length - 1;
            while (second < third) {
                sum = nums[first] + nums[second] + nums[third];
                res = sum - x;
                // 与目标数相等，返回sum
                if (res == 0){
                    return sum;
                }                
                abs = Math.abs(res);
                if (most > abs) {
                    most = abs;
                    result = sum;
                }
                // 差值大于0，左下标右移动，数组已经排好序，可以使sum值增大，且去重
                if (res > 0) while (second < third && nums[third] == nums[--third]) ;
                // 差值小于0，右下标左移动，数组已经排好序，可以使sum值减小，且去重
                if (res < 0) while (second < third && nums[second] == nums[++second]) ;
            }
        }
        return result;
    }
}
```