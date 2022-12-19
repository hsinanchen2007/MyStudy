### 解题思路
二分法（递归实现）
![image.png](https://pic.leetcode-cn.com/1668b4bdbac4587c9b75abf00a22fd76991a868e13a33a866bda035fea3195bd-image.png)

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = {-1,-1};
        if(nums.length == 0)
            return res;
        if(nums.length ==1)
            return nums[0] == target ? new int[]{0,0} : res;
        divide(res,nums,target,0,nums.length - 1,true);
        divide(res,nums,target,0,nums.length - 1,false);
        return res;
    }
    public void divide(int[] result,int[] nums,int target,int low,int high,boolean flag){
        if (low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] < target)
                divide(result,nums,target,mid + 1,high,flag);
            else if(nums[mid] > target)
                divide(result,nums,target,low,mid - 1,flag);
            else {
                if(flag){
                    result[0] = mid;
                    divide(result,nums,target,low,mid - 1,flag);
                }else {
                    result[1] = mid;
                    divide(result,nums,target,mid + 1,high,flag);
                }
            }
        }
        return;
    }
}
```