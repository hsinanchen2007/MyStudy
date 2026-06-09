### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int index = 0;
        //列出数组首元素大于目标值的特殊情况
        if(nums[0]>=target) return 0;

        for(int i=0;i<nums.length-1;i++){
            //若数组元素小于目标值，则往后遍历
            if(nums[i+1]<target){
                continue;
            }
            //当元素不小于目标值时，返回下标
            else    
                return i+1;
        }
        //结束循环则返回数组长度
        return nums.length;
    }
}
```