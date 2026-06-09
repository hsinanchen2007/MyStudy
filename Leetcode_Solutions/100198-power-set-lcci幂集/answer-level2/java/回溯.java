### 解题思路
还好给出的数组不可能是重复的

### 代码

```java
class Solution {

    List<List<Integer>> res = new ArrayList<>();
    int len;
    public List<List<Integer>> subsets(int[] nums) {
        Arrays.sort(nums);
        len = nums.length;
        for (int k = 1; k <= len; k++) {
            List<Integer> had = new ArrayList<>();
            dfs(nums, 0, k, had);
        }
        res.add(new ArrayList<>());
        return res;
    }
    void dfs(int[] nums, int start, int sum, List<Integer> had) {
        if (sum == 0) {
            res.add(new ArrayList(had));
            return;
        }
        for (int i = start; i < len; i++) {
            had.add(nums[i]);
            dfs(nums, i + 1, sum - 1, had);
            had.remove(had.size() - 1);
        }
    }
}
```