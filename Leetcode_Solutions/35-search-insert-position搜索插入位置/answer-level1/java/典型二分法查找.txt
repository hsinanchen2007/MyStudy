### 解题思路
1、边界问题：先只用考虑最大值边界，最小值边界问题已经在low 中考虑到，设置的low=0
2、二分法查找，判断思路:
2.1、 nums[mid] = target  :找到数据，直接返回mid
2.2、 nums[mid] > target  :中间值比对比值大，target 在 low-mid范围 ，high=mid 
2.3、 nums[mid] < target  :中间值比对比值小，target 在 mid+1 - high范围
注意的是：这里是 mid+1，原因，如果这里还是mid 的话，判断条件 low<high 会死循环。
原因在于：求中间算法，除以2一直取的是低位，所以最后计算到最后未找到时，只有当低位+1,才会出现 low=high跳出循环。

 
### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int low = 0;
        int high = nums.length -1;
        int mid;
        if(nums[high]<target){
            return nums.length;
        }

        while (low<high){
            mid = low + ((high-low)>>1);
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                high = mid;
            }else {
                low = mid+1;
            }

        }
        return low;
    }
}
```