### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private int n;
    private int target;
    private int[] candidates;
    private List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if (candidates == null || candidates.length == 0) return res;
        this.n = candidates.length;
        this.target = target;
        this.candidates = candidates;
        Arrays.sort(this.candidates); 
        dfs(0, 0, new ArrayList<Integer>());
        return res;
    }

    private void dfs(int index, int sum, List<Integer> now) {
        if (sum == target) {
            res.add(new ArrayList(now));
            return ;
        }
        for (int i = index; i < n; i++) {
            if (sum + candidates[i] <= target) {
                now.add(candidates[i]);
                dfs(i, sum + candidates[i], now);
                now.remove(now.size() - 1);
            } else break;
        }
    }
}
```