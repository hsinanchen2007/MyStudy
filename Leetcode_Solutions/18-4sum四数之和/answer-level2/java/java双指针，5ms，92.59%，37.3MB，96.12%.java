### 解题思路
1. 排序
2. 如果target比可能的最小值小，或比可能的最大值大，则没结果
3. 固定前两个值，剩下两个用双指针。感觉5sum，Nsum都可以用这个做法，时间复杂度是O(n^N-1)
4. 需要注意的是，如果要求解不重复，则必须跳过连续重复值，否则会有重复解。

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<>();
        //if array length less than 4, throw exception
        if (nums.length<4) {
            return result;
        }
        //sort
        Arrays.sort(nums);
        //if target is less than min 4 sum, or target is greater than max 4 sum, there is no solution
        if (target < (nums[0] + nums[1] + nums[2] + nums[3]) ||
            target > (nums[nums.length-4]+nums[nums.length-3]+nums[nums.length-2]+nums[nums.length-1])) {
            return result;
        }
        //fix first two numbers, then double point solution
        for (int i=0;i<nums.length-3;i++) {
            //skip continuous same number
            if (i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            for (int j=i+1;j<nums.length-2;j++) {
                //skip continuous same number
                if (j>i+1 && nums[j]==nums[j-1]) {
                    continue;
                }
                int left=j+1,right=nums.length-1;
                //if target is less than min sum in current double point loop,
                //or target is greater than max sum in current double point loop
                //there is no need to proceed, because it's impossible to find solution anymore
                if (left!=right) {
                    int minSumInThisDoublePoint = nums[i] + nums[j] + nums[left] + nums[left + 1];
                    int maxSumInThisDoublePoint = nums[i] + nums[j] + nums[right] + nums[right - 1];
                    if (target < minSumInThisDoublePoint || target > maxSumInThisDoublePoint) {
                        continue;
                    }
                }
                while (left<right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum==target) {
                        List<Integer> item = new ArrayList<>();
                        item.add(nums[i]);
                        item.add(nums[j]);
                        item.add(nums[left]);
                        item.add(nums[right]);
                        result.add(item);
                        //whatever left++ or right--, only one thing is that skipping continuous same number is mandatory
                        left++;
                        //skip continuous same number
                        while (left!=right && nums[left]==nums[left-1]) {
                            left++;
                        }
                    } else if (sum<target) {
                        left++;
                        //skip continuous same number
                        while (left!=right && nums[left]==nums[left-1]) {
                            left++;
                        }
                    } else {
                        right--;
                        //skip continuous same number
                        while (left!=right && nums[right]==nums[right+1]) {
                            right--;
                        }
                    }
                }
            }
        }
        return result;
    }
}
```