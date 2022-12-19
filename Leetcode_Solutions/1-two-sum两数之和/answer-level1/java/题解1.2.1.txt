### 解题思路
省去了判断是否是同一个对象的步骤, 因为在表中寻找时, 当先数字还没有put到表中.

### 代码

```java
class Solution {
     public int[] twoSum(int[] nums, int target){
        Map<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            int complement = target - nums[i];
            if(map.containsKey(complement)){
                return new int [] {i,map.get(complement)};
            }
            map.put(nums[i],i);
        }
        throw new IllegalArgumentException("No two sum solution.");
    }
    
}
```