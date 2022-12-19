### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
            int length=nums.length;
        for(int i=0;i<length;i++){
            //如果目标值小于第一个元素
             if(target<nums[0]){
                 return 0;
        }
             //如果目标值大于最后一个元素
        if(target>nums[length-1]){
            return length;
    }
            //如果目标值存在
         if( nums[i]==target){
                    return i;
                }
                 //如果目标值在排序数组之间
        if(target<nums[i]&&target>nums[i-1]){
            return i; 
              }
        }
        return 0;
    }
}
```