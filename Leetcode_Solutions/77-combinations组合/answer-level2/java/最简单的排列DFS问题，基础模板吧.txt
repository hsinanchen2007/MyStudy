### 解题思路
DFS

### 代码

```java
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> results = new ArrayList<>();
        if (n == 0) {
            return results;
        }
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        
        dfs(nums, 0, new ArrayList<>(), results, k);

        return results;
    }

    private void dfs(int[] nums, int index, ArrayList<Integer> subsets, List<List<Integer>> results, int k) {
        if(subsets.size() == k) {
            results.add(new ArrayList<>(subsets));
        }

        for (int i = index; i < nums.length; i++) {
            subsets.add(nums[i]);
            dfs(nums, i + 1, subsets, results, k);
            subsets.remove(subsets.size() - 1);
        }
    }
}
```