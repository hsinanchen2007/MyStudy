只要明确了可以使用回溯，之后直接套模板就行了
```
public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        int sum = 0;
        backtrack(candidates, target, 0, sum, res, temp);
        return res;
    }

private void backtrack(int[] candidates, int target, int start, int sum, List<List<Integer>> res, List<Integer> temp) {
        if (sum == target) {
            res.add(new ArrayList<>(temp));
            return;
        } else if (sum > target)
            return;
        for (int i = start; i < candidates.length; i++) {
            sum += candidates[i];
            temp.add(candidates[i]);
            backtrack(candidates, target, i, sum, res, temp);
            temp.remove(temp.size() - 1);
            sum -= candidates[i];
        }
    }
```
