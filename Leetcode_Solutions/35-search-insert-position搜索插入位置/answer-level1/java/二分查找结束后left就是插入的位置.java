### 解题思路
此处撰写解题思路
在二分查找过程中，如果相等，则直接返回，当循环能够运行完毕时，说明此元素不存在，此时left的位置（实际为right+1）就是待插入元素的位置，因为right仍然是合法的位置！！
### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        if(nums.length==0) return 0;
        int left=0,right=nums.length-1,mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) left=mid+1;
            else if(nums[mid]>target) right=mid-1;
        }
        //能走到这一步，说明，没有此元素。
        return left;

    }
}
```