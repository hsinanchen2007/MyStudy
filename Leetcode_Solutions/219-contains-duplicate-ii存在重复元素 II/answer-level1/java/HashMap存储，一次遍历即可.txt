### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer,Integer> maps = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(!maps.containsKey(nums[i])){
                maps.put(nums[i],i);
            }else{
                if (i-maps.get(nums[i]) <=k){
                    return  true;
                }else{
                    maps.put(nums[i],i);
                }
            }
        }
        return false;
    }
}
```