### 解题思路
此处撰写解题思路
这里采用先找index再做一次BST遍历
index这个最小值索引，是通过其特性来寻找，其是最小值，那么我们找一个index，跟index+1两个值进行比较
相邻的点，正常的升序的话，肯定前者较小，但是如果index+1是这个最小值的索引的话，就会后者较小，那么当遍历到这种情况的时候，直接输出index+1作为锚点，即return index=index+1
在循环体中先做判定，index 跟index+1 的大小，当满足升序时，再进行传统的遍历，二叉遍历

注意点就是这个index的寻找过程，我们先判定mid=(left+right)/2,然后把mid跟left做判断，
如果left＜mid，那么选择mid右侧继续循环
如果left＞mid，那么选择mid左侧继续循环
如果left==mid，那么要小心了，这里是采用left作为锚点进行比较，那么如果left==mid的情况发生了说明left左侧已经没有遍历空间了，都相等了，因为题目给定的不重复，就意味着left这个index跟mid 的index重叠了，就需要走mid右侧空间。
### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int mid=0;
        int left=0;
        int right=nums.length-1;
        int index=0;

        if(nums.length==0)
            return -1;

        if(nums.length==1)
            return nums[0]==target ? 0:-1;

        if(nums[left]<nums[right])
        {
            index=0;
        }
        else{
            while(left<=right)
            {
                mid=left+(right-left)/2;
                if(nums[mid]>nums[mid+1])
                {
                    index=mid+1;
                    break;
                }
                else{
                    if(nums[left]>nums[mid])
                        right=mid-1;
                    else
                        left=mid+1;
                }
            }
        }

        // System.out.println(index);
        //0-index 为大的数段， index+1 - end 为小的数段
        // +index, 做二分查找,取余。
        left=0+index;
        right=nums.length-1+index;
        int len=nums.length;
        if(target<nums[index])
            return -1;
        while(left<=right)
        {
            mid=left+(right-left)/2;

            if(nums[mid%len]<target)
            {
                left=mid+1;
            }
            else if(nums[mid%len]>target)
                right=mid-1;
            else
                return mid%len;
        }
        return -1;

    }

}
```