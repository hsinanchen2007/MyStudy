```java
class Solution {
    List<List<Integer>> res = new ArrayList<>();
    int[] candidates;
    int n;
    int target;
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        this.n = candidates.length;
        Arrays.sort(candidates);
        this.candidates = candidates;
        this.target = target;
        helper(new ArrayList<Integer>(), 0, 0);
        return res;
    }

    void helper(List<Integer> cur, int sum, int start) {
        if (sum > target) return;
        if (sum == target) {
            res.add(new ArrayList<>(cur));
        }
        for (int i = start; i < n; i ++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            cur.add(candidates[i]);
            helper(cur, sum + candidates[i], i + 1);
            cur.remove(cur.size() - 1);
        }
    }
}
```