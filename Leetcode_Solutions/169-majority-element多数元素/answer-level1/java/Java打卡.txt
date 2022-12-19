### 解题思路


### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer, Integer> uniqueNums = new HashMap<Integer, Integer>();
        int i, majority = Integer.MAX_VALUE, majoritySize = 0;
        for(i = 0;i < nums.length;i ++){
            if(uniqueNums.containsKey(nums[i]))
                uniqueNums.put(nums[i], uniqueNums.get(nums[i]) + 1);
            else
                uniqueNums.put(nums[i], 1);
            if(nums[i] == majority)
                majoritySize ++;
            else if(uniqueNums.get(nums[i]) > majoritySize){
                majoritySize = uniqueNums.get(nums[i]);
                majority = nums[i];
            }
            if(majoritySize > nums.length / 2)
                return majority;
        }
        return majority;
    }
}
```