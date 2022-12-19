# 打家劫舍的分治算法：

我做这题第一反应是用分治算法来实现，但是参考题解时未见相同思路，故提出来分享一下。

**抽象数学模型：**  
- 从数组中取不相邻数组成子列的最大和。



**思路：**
- 对于任意数组rob[low,high]，可以取中间位rob[mid],则rob[low,high]的最大值无非以下两种情况之一:
    1. **不包含rob[mid]**：此时rob[low,high]的值为rob[low,mid-1]+rob[mid+1,high]
    2. **包含rob[mid]**：此时不能包含rob[mid-1]和rob[mid+1]，故为rob[low,mid-2]+rob[mid]+rob[mid+2,high]

- 边界条件：
-     当low>high时，数组不存在，返回0
-     当low==high时，数组只有一个元素，返回rob[low]

代码实现
```java []
class Solution {
    public int rob(int[] nums) {
        return rob(nums ,0,nums.length-1);

    }

    public int rob(int[] nums, int start, int end) {

        if (start > end) return 0;//边界条件1
        if (start == end) return nums[start];//边界条件2
        int mid=start+(end-start)/2;
        return Math.max(rob(nums,start,mid-1)+rob(nums,mid+1,end),
                        rob(nums,start,mid-2)+nums[mid]+rob(nums,mid+2,end));

    }
}
```
**复杂度分析**

- 时间复杂度:O(nlogn):
-       遍历一次即可，复杂度为O(n)，递归深度O(logn),综合为O(nlogn)。
- 空间复杂度：O(n):
-       每次递归半个数组，最坏时为n/2+n/4+n/8……=n。综合为O(n)