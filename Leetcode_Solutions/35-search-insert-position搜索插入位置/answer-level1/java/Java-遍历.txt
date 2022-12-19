### 解题思路
首先排除两种特殊情况，目标值比第一个元素小，目标值比最后一个元素大。
然后遍历数组，能找出相等的值，直接返回索引；如果没有相等的值，找到比前一个元素大，后一个元素小的位置，返回当前索引并加一。

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        if(target<nums[0]){
            return 0;
        }
        if(target>nums[nums.length-1]){
            return nums.length;
        }
        for(int i = 0; i < nums.length; i++) {
            if(target == nums[i]){
                return i;
            }
            if(nums[i] < target && target < nums[i+1]){
                return i+1;
            }
        }
        return -1;
    }
}
```