### 解题思路
    线性扫描本数组，将返回的数组初始值设为{-1，-1}，即没找到。指针i从0号元素从左向右扫描，扫描得到第一个与目标值相等的元素后将i填入返回数组的位置0。如果未找到，说明排序数组中没有这个元素，返回{-1，-1}。若找到后再从右向左扫描，即可得到最后一个位置的索引序号 。
### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int []targetrange={-1,-1};
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]==target)
            {
                targetrange[0]=i;
                break;
            }
        }

        if(targetrange[0]==-1)
        {
            return targetrange;
        }

        for(int j=nums.length-1;j>=0;j--)
        {
            if(nums[j]==target)
            {
                targetrange[1]=j;
                break;
            }
        }
        return targetrange;
        
    }
}
```