执行用时 :2 ms, 在所有 Java 提交中击败了99.20%的用户
内存消耗 :57.1 MB, 在所有 Java 提交中击败了100.00%的用户
### 解题思路
左边和右边同时往数组中间扫描，如果此时左右两边和大于target，右边那个必定得往左移，因为左边往右移和还是大，没意义。和小于target同理。
### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int ans[] = new int[2] ;
        int i=0,j=nums.length-1 ;
        for(;;){
            if(nums[i]+nums[j]>target){
                j-- ;
                continue;
            }
            if(nums[i]+nums[j]<target){
                i++ ;
                continue;
            }
            ans[0] = nums[i] ;
            ans[1] = nums[j] ;
            break;
        }
        return ans ;
    }
}
```