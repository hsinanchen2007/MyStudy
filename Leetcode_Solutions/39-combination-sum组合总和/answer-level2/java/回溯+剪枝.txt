### 解题思路
很简单的回溯，注意下回溯时的复原即可

### 代码

```java
class Solution {

    int[] candidates;
    int target;
    List<List<Integer>> res;
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        this.candidates = candidates;
        this.target = target;
        res = new ArrayList<>();
        List<Integer> had = new ArrayList<>();
        dfs(had, 0, 0);
        return res;
    }

    void dfs(List<Integer> had, int start, int sum) {
        if (sum == target) {
            res.add(new ArrayList(had));
            return;
        }
        if (sum > target) return;
        for (int i = start; i < candidates.length; i++) {
            had.add(candidates[i]);
            sum += candidates[i];
            dfs(had, i, sum);
            had.remove(had.size() - 1);
            sum -= candidates[i];
        }
    }
}
```