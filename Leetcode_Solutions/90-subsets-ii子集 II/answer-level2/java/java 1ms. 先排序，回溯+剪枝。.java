### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private int n;
    private int[] nums;
    private boolean[] marked;
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        if (nums == null || nums.length == 0) return res;
        this.n = nums.length;
        this.nums = nums;
        Arrays.sort(this.nums);
        marked = new boolean[n];
        dfs(0, new ArrayList<Integer>());
        return res;
    }

    private void dfs (int index, List<Integer> now) {
        res.add(new ArrayList(now));
        for (int i = index; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !marked[i - 1]) continue; 
            marked[i] = true;
            now.add(nums[i]);
            dfs(i + 1, now);
            now.remove(now.size() - 1);
            marked[i] = false;
            
        }
    }
}
```