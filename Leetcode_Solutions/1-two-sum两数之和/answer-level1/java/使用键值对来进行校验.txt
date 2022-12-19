### 解题思路
将元素作为key，将下标作为value
在循环的时候，i是递增的，也可以代表数组递增的下标
当map中包含了差数的key的时候，就说明减数也put在了map中

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i = 0;i < nums.length;i++){
            int num = target - nums[i];
            if(map.containsKey(num)){
                return new int[]{map.get(num),i};
            }
            map.put(nums[i],i);
        }
        return null;
    }
}
```