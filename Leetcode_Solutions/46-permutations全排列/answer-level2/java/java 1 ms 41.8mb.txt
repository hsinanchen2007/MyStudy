### 解题思路
觉得官方的有点麻烦，重新写了一下，还是调序之后在调回来。

### 代码

```java
class Solution {
    List<List<Integer>> res = new LinkedList<>();
    public List<List<Integer>> permute(int[] nums) {
        dfs(nums, 0);
        return res;
    }

    private void dfs(int[] nums, int i) {
        if (nums.length == i) {
            List<Integer> cmp = new LinkedList<>();
            for (int k : nums) {
                cmp.add(k);
            }
            res.add(cmp);
            return;
        }
        for (int k=i; k<nums.length; k++) {
            swap(nums, k, i);
            dfs(nums, i+1);
            swap(nums, k, i);
        }
    }

    private void swap(int[] nums, int k, int i) {
        int temp = nums[k];
        nums[k] = nums[i];
        nums[i] = temp;
    }
}
```