```
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(candidates); // 先排序，通过排序，后续方便去重
        backtrack(candidates, 0, target, new ArrayList<>(), res);

        return res;
    }

    void backtrack(int[] candidates, int start, int target, List<Integer> output, List<List<Integer>> res) {
        if (target == 0) {
            res.add(new ArrayList<>(output));
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            if (candidates[i] > target) { // 由于是递增序列，当大于target，就不用再回溯
                break;
            }
            if (i > start && candidates[i] == candidates[i - 1]) { //去重，跟前一个比较，比如相等，那么肯定重复了
                continue;
            }

            output.add(candidates[i]);
            backtrack(candidates, i + 1, target - candidates[i], output, res);
            output.remove(output.size() - 1);
        }
    }
```
