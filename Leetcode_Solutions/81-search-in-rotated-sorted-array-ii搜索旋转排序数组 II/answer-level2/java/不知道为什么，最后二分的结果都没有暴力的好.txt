### 解题思路
暴力的时间一样，空间更小
public boolean search(int[] nums, int target) {
        for (int i=0;i<nums.length;i++){
            if (nums[i]==target)
                return true;
        }
        return false;
    }

### 代码

```java
class Solution {
    public boolean search(int[] nums, int target) {
        if (nums.length==0)
            return false;
        int left=0,right=nums.length-1;
        while (left<right){
            if (left+1==right)
                break;
            int mid=(left+right)/2;
            if (nums[mid]>nums[left]){//左有序
                if (target<=nums[mid] && target >=nums[left])
                    right=mid;
                else
                    left=mid;
            }
            else if (nums[mid]<nums[left]){
                if (target>=nums[mid] && target <=nums[right])
                    left=mid;
                else
                    right=mid;
            }
            else{
                if (target==nums[mid])
                    return true;
                else{
                    left++;
                }
            }
        }
        return nums[left] == target || nums[right] == target;
    }
}
```