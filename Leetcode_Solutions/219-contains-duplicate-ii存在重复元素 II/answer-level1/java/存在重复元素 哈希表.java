```
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        //哈希表一边写一边比较
        //如果没有nums[i]，写入其和其位置
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i=0; i<nums.length;i++){
            if(!map.containsKey(nums[i])){
                map.put(nums[i],i);
            }
            //如果之前有这个数，看是否距离<k
            else{
                int index = map.get(nums[i]);
                if(i-index<=k)//存在，可以直接返回true
                    return true;
                //距离长，不能直接返回false，可能后面有这个数，距离小于k
                //要更新nums[i]位置为现在位置
                else{
                    map.put(nums[i],i);
                }
            }
        }
        return false;
    }
}
```
