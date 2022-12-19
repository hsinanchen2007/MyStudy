### 解题思路
用map或者双指针

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> map =  new HashMap();
        for(int i=0;i<nums.length;i++){
            if(map.get(target-nums[i])!=null){
                return new int[]{nums[i],target-nums[i]};
            }
            map.put(nums[i],nums[i]);
        }
        return new int[]{};
    }
}
```