### 解题思路
1. target小于等于”下标数“直接返回下标（要么不进行替换，直接返回下标，要么替换，代替原来的数，还是返回当前比较的数的下标）
2. 若遍历完成后仍不能返回，则表示target大于最大数，此时返回length

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int length = nums.length;
        for(int i = 0; i < length; i++){
            if(target <= nums[i]){
                return i;
            }
        }
        return length;
    }
}
```