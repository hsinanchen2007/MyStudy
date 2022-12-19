### 解题思路
因为寻找第一个比他大的数的index或者是他本身，
那么就类似最右侧边界的寻找
每次如果等于target就直接输出index
然后相同的变换边界，但是我们的终止条件是left>right
判断如果此时区间为left left，那么就还有一次循环可以走
极端到两种边界条件
12345 0/6，target为0或者6
0：二分查找直接推进到1这个数，即left跟right都为0——index，指向1，
target在left左侧，那么因为mid=left，所以mid>target,right就会变成left-1，退出循环，此时输出left就是第一个比target大的数字。
6：二分查找直接推进到5这个数，即left跟right都为4,——index，指向5
target在right右侧，因为此时left=right， 标记成left，left，那么mid=left，left增大为mid+1，
直接退出循环，且命中右侧第一个比target大的数。
我们的二分查找最终能锁定在一个靠近第一个比target的地方，要么是左边要么是右边，上述两种情况都反映出left是这个index索引，所以直接返回left。

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int left=0;
        int right=nums.length-1;
        int mid=0;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        return left;

    }
}
```