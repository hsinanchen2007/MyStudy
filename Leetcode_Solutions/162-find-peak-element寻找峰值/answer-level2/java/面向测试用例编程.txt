### 解题思路
此处撰写解题思路
![捕获12.PNG](https://pic.leetcode-cn.com/89596f9f14036a8803c0332c29432333716305b1c520db2a8aa2d20d53e5a5f1-%E6%8D%95%E8%8E%B712.PNG)

### 代码

```java
class Solution {
    public int findPeakElement(int[] nums) {
        if(nums==null||nums.length<2){
            return 0;
        }
        if(nums.length==2){
            return nums[0]>nums[1]?0:1;
        }
        int l=1,r=nums.length-2;
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[nums.length-1]>nums[nums.length-2]){
            return nums.length-1;
        }
        while(l<=r){
            if(nums[l]>nums[l-1]&&nums[l]>nums[l+1]){
                return l;
            }else{
                l++;
            }
            if(nums[r]>nums[r+1]&&nums[r]>nums[r-1]){
                return r;
            }else{
                r--;
            }
        }
        return 0;
    }
}
```