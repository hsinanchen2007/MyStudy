依次遍历数组，分为两大类情况：
1.map中不包含遍历的值，此时，以数组的值为key，下标为value，put进map中；
2.map中包含遍历的值，此时，将下标取出，若旧下标与当前下标的差值小于或等于k，返回true即可；若下标的差值大于k，用新下标覆盖旧下标，继续遍历即可。如果最终都没返回true，那么说明没有符合条件的记录，返回false即可。
```
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0;i < nums.length;i++) {
            int num = nums[i];
            if(!map.containsKey(num)) {
                map.put(num, i);
            } else {
                int index = map.get(num);
                if((i - index) <= k) {
                    return true;
                } else {
                    map.put(num, i);
                }
            }
        }
        return false;
    }
}
```
