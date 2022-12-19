### 解题思路
第一题我就对剑指offer佩服的五体投地
### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        //解法1 放入set中，如果放入一个数字后，大小没变说明这个数字是重复的
        // HashSet<Integer> set= new HashSet<Integer>();
        // for(int i=0;i<nums.length;i++){
        //     int currentSize = set.size();
        //     set.add(nums[i]);
        //     if(currentSize==set.size()){
        //         return nums[i];
        //     }
        // }

        // 数组长度为n，数字都小于n
        // 那么如果没有重复的数字，排序后应该的顺序是 数字m 的下标应该恰好是m。
        // 如果又重复的，那么我们尝试将一个重复的数字m放入m位置的时候，num[m] ==m
        // 就会为真，这是就找到了m。
        for(int i=0;i<nums.length;i++){
            int currentValue = nums[i];
            while(currentValue!=i){
                if(nums[currentValue]==currentValue){
                    return currentValue;
                }
                nums[i] = nums[currentValue];
                nums[currentValue] = currentValue;
            }
        }

        return nums[0];
    }
}
```