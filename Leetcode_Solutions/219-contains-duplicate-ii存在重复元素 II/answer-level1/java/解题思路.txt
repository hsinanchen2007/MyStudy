利用map存储，key=元素，value=元素下标。判断map.get(元素)是否为空，不为空，则比较当前下标和value是否<=k。如果是则返回true，不是则替换下标为当前下标
```
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer,Integer> map = new HashMap<>();
        int length = nums.length;
        for(int i=0;i<length;i++){
            Integer value = map.get(nums[i]);
            if(value != null && i - value <= k){
                return true;
            }
            map.put(nums[i], i);
        }
        return false;
    }
}
```
