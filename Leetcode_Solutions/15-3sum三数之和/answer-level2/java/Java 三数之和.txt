### 解题思路
解题思路见代码注释。

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        // 1. 首先对数组进行排序，一方面可以较好的解决重复问题，另一方面求三数之和可以缩小范围
        Arrays.sort(nums);

        // res变量存储最终要返回的结果
        List<List<Integer>> res = new ArrayList<>();
        for(int k = 0; k < nums.length - 2; k++){
            if(nums[k] > 0) {
                break;
            } // 如果第一个元素已经大于0，那如何找到与其构成和为0的其他两个元素？？？所以break！！！

            if(k > 0 && nums[k] == nums[k - 1]) {
                continue;
            } // 遇到重复元素忽略即可

            // i和j从k之后元素的两端开始求和，判断是否为k对应元素的相反数，如果是则找到一个结果
            int i = k + 1, j = nums.length - 1;
            while(i < j){
                int sum = nums[k] + nums[i] + nums[j]; // 求三数之和
                if(sum < 0){ // 小于0，则left即i向前走
                    while(i < j && nums[i] == nums[++i]);
                } else if (sum > 0) { // 大于0，则right即j向后走
                    while(i < j && nums[j] == nums[--j]);
                } else { // 等于0，则此时是一个结果，同时i和j走向下一个元素，继续判断是否有下一个解
                    res.add(new ArrayList<Integer>(Arrays.asList(nums[k], nums[i], nums[j])));
                    while(i < j && nums[i] == nums[++i]);
                    while(i < j && nums[j] == nums[--j]);
                }
            }

            // 内循环结束，则继续外层循环元素的定位，进而判断是否有满足条件的解
        }
        return res;
    }
}
```