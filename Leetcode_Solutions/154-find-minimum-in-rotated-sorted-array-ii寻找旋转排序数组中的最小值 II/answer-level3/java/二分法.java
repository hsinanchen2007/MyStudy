### 解题思路
![捕获11.PNG](https://pic.leetcode-cn.com/3a23351452258ce3c3375e00f955bef6586cd473712e695430c05e219d8d8b1b-%E6%8D%95%E8%8E%B711.PNG)
此处撰写解题思路

### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        int l=0,r=nums.length-1;
        while(l<r){
            while(l<r&&nums[l]==nums[l+1]) l++;
            while(l<r&&nums[r]==nums[r-1]) r--;
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return nums[l];
    }
}
```