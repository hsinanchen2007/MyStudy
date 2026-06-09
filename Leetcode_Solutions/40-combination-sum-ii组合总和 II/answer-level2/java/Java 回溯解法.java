### 解题思路
回溯算法

### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<>();
        dfs(res, candidates, new ArrayList<>(), target, 0);
        return res;
    }

    public void dfs(List<List<Integer>> res, int[] candidates, List<Integer> temp, int target, int nextIndex){
        if (target == 0){
            if (!res.contains(temp)) {
                res.add(temp);
            }
            return;
        }
        if (nextIndex >= candidates.length || target < 0 || candidates[nextIndex] > target){
            return;
        }
        for (int i = nextIndex; i < candidates.length; i++) {
            if (candidates[i] > target){
                return;
            }
            List<Integer> list = new ArrayList<>(temp);
            list.add(candidates[i]);
            dfs(res, candidates, list, target - candidates[i], ++nextIndex);
        }
    }
}
```