### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> hashmap = new HashMap<>();
        int[] res = new int[2];

        for(int i = 0; i < nums.length; i++){
            if(!hashmap.containsKey(nums[i])){
                hashmap.put(nums[i], 1);
            }
            else{
                hashmap.put(nums[i], hashmap.get(nums[i])+1);
            }
        }

        for(int i = 0; i < nums.length; i++){
            hashmap.put(nums[i], hashmap.get(nums[i])-1);
            int left = target - nums[i];
            if(hashmap.containsKey(left) && hashmap.get(left) > 0){
                res[0] = nums[i];
                res[1] = left;
            }
            hashmap.put(nums[i], hashmap.get(nums[i])+1);
        }
        return res;
    }
}
```