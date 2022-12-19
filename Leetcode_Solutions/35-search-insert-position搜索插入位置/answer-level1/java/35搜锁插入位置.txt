执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :38.7 MB, 在所有 Java 提交中击败了83.15%的用户
### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        if(nums == null || nums.length == 0) return 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] >= target){
                return i;
            }
        }
        return nums.length;
    }
}
```