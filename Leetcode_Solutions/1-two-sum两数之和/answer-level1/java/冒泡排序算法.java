### 解题思路
双重遍历,有点像冒泡排序

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        /**
         * 给定 nums = [2, 7, 11, 15], target = 9
         *
         * 因为 nums[0] + nums[1] = 2 + 7 = 9
         * 所以返回 [0, 1]
         */
        int[] ins=new int[2];
        here:
        for (int i = 0; i < nums.length-1; i++) {
            int num = nums[i];
            for (int j = i+1; j < nums.length; j++) {
                int num1 = nums[j];
                if (num+num1==target){
                    ins[0]=i;
                    ins[1]=j;
                    break here;
                }
            }
        }
        return ins;
    }

}
```