执行用时 :0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :38.1 MB, 在所有 Java 提交中击败了5.14%的用户

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int left = 0;
        for(int i = 0;i < nums.length;++i){
            if(nums[i] != val){
                nums[left] = nums[i];
                left++;
            }
        }
        return left;
    }
}
```