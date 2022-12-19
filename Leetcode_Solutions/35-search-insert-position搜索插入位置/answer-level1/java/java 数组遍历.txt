### 解题思路
本人使用最普通的遍历算法，因预设数组为排序好的数组，故而可设想，若遇到第i个数值大于目标数值，则说明数组中不存在此数组，则需要在第i位置插入目标数值。
### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        for(int i=0;i<nums.length;i++){
           if (nums[i]>=target){ //若数组中的值大于或等于目标值，则进行插入；
                return i;
            }
        }
        return nums.length; //若数组遍历完仍未找到数据，则再数组末尾插入目标值
    }
}
```