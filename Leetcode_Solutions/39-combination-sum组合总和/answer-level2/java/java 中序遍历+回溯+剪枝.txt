```
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if (candidates == null) {
            return new ArrayList<>();
        }
        Arrays.sort(candidates);
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        backtrack(0, candidates, target, result, temp);
        return result;
    }
    public void backtrack(int start, int[] candidates, int target, List<List<Integer>> result, List<Integer> temp) {
        if (target < 0) return;
        if (target == 0) {
            result.add(new ArrayList<>(temp));
        } else {
            for (int i = start; i < candidates.length; i++) {
                if(target < candidates[i]) break;
                temp.add(candidates[i]);
                backtrack(i, candidates, target - candidates[i], result, temp);
                temp.remove(temp.size() - 1);
            }
        }
    }
}
```
