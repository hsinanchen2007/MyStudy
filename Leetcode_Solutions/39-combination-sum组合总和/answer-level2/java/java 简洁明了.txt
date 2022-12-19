```

    public List<List<Integer>> combinationSum(int[] candidates, int target) {

        Arrays.sort(candidates);

        List<List<Integer>> results = new ArrayList<>();
        List<Integer> result = new ArrayList<>();
        back(results, result, candidates, target, 0);

        return results;

    }

    /**
     * @param results    结果集
     * @param result     结果
     * @param candidates 候选人
     * @param target     目标值
     * @param level      层级
     */
    public void back(List<List<Integer>> results, List<Integer> result, int[] candidates, int target, int level) {

        if (target == 0) {
            results.add(new ArrayList<>(result));
            return;
        }

        for (int i = level; i < candidates.length && target - candidates[i] >= 0; i++) {
            result.add(candidates[i]);
            back(results, result, candidates, target - candidates[i], i);
            result.remove(result.size() - 1);
        }

    }

```
