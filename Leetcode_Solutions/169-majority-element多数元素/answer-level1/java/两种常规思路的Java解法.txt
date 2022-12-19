1. 使用`HashMap`，`key`为数组中的元素，`value`为元素对应的频次。当某个元素的频次大于`n/2`时，则返回结果
```java
class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            if(!map.containsKey(nums[i])){
                map.put(nums[i], 1);   
            }else{
                map.put(nums[i], map.get(nums[i]) + 1);
            }
            if(map.get(nums[i]) > nums.length / 2){
                    return nums[i];
            }
        }
        return -1;
    }
}
```

2. 在数组排序后，众数一定会出现在数组的中间位置。
```java
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }
}
```