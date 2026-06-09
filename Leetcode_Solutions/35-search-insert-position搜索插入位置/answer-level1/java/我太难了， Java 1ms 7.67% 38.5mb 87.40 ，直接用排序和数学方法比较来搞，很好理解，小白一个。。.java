### 解题思路
1.直接排序。
2.两个两个比较，如果找到target在两个数值中间，直接返回大的下标。
3.完成。

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
       Arrays.sort(nums);
        int res=0;
        if(target<nums[0]) return 0;
        if(target>nums[nums.length-1]) return nums.length;
        for(int i=1;i<nums.length;i++){
            if(target>Math.min(nums[i-1],nums[i])&&target<=Math.max(nums[i-1],nums[i])){
                res=i;
            }
            continue;
        }
        return res;
    }
}
```