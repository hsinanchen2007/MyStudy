### 解题思路
考虑到各种情况即可，内存消耗比较大

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int p =0;
        if(nums[0]>target) p=0;
        else{
                for(int i=0;i<=nums.length-1;i++){
                     if(nums[i]==target) return p=i;
                    else if(i!=nums.length-1&&nums[i+1]>=target) return p=i+1;
                    else if(i==nums.length-1) return p=i+1;
            }
        }
        return p;
    }
}
```