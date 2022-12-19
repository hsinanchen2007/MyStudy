### 解题思路
本题可以采用迭代方式下的二分查找算法，没查找一次都进行以下判断：
1、下标和数字不同再分左边的数字是否相同分别分析
        情况1：如果nums[0]不等于mid时，即一开始就缺了，则缺的数应该等于mid，即0
        情况2：因为nums[mid]!=mid，所以如果mid > 0 && nums[mid-1]==mid-1，则缺的数应该等于mid
2、如果下标和数字相同就在右边查找

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int left=0;
        int right=nums.length-1;
        while(left<=right) {
            int mid=(left+right)>>1;
            if(nums[mid]!=mid) {
                if(mid==0 || mid > 0 && nums[mid-1]==mid-1)
                    return mid;
                right=mid-1;
            }else {//如果下标和数字相同就在右边查找
                left=mid+1;
            }
        }
        //到这一步，说明前面数字都不缺了，那只能是少最后一个数
        return nums.length;
    }
}
```