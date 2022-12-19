### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private int[] nums;
    private boolean[] marked;
    private int n;
    private List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> permuteUnique(int[] nums) {

        if (nums == null || nums.length == 0) return res;
        this.nums = nums;
        n = nums.length;
        marked = new boolean[n];
        Arrays.sort(this.nums); 
        dfs(0, new ArrayList<Integer>());
        return res;
    }

    private void dfs(int index, List<Integer> now) {
        if (index == n) {
            res.add(new ArrayList(now));
            return ;
        }
        for (int i = 0; i < n; i++) {
            if (marked[i] || i > 0 && nums[i] == nums[i - 1] && !marked[i - 1]) continue;
            now.add(nums[i]);
            marked[i] = true;
            dfs(index + 1, now);
            marked[i] = false;
            now.remove(index);
        }
    }
}
```