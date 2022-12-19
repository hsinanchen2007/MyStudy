### 解题思路
执行用时 :70 ms, 在所有 Java 提交中击败了71.49%的用户
内存消耗 :48.2 MB, 在所有 Java 提交中击败了100.00%的用户

### 代码

```java
class Solution {
    private int[] nums;
    public Solution(int[] nums) {
        this.nums = nums;
    }
    
    public int pick(int target) {
        Random r = new Random();
        int bound = nums.length;
        int index = r.nextInt(bound);
        while(nums[index]!=target){
            index = r.nextInt(bound);
        }
        return index;
    }
    
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
```