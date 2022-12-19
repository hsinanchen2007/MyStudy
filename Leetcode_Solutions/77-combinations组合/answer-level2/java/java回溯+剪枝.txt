```
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new LinkedList<>();
        // 排序，用于剪枝
        Arrays.sort(candidates);
        backtrack(result, new LinkedList<>(), target, 0, candidates);
        return result;
    }

    /**
    * residue 剩余要加的数
    /
    private void backtrack(List<List<Integer>> ans, List<Integer> temp, int residue, int pos, int[] candidates) {

        if (residue == 0) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        if (residue < 0) {
            return;
        }
        for (int i = pos; i < candidates.length; i++) {
            // 在排序好的情况下， 如果当前剩余的数比candidates[i] 还要小，那么后面的所有candidate都不合适
            if (residue < candidates[i]) {
                continue;
            }
            int candidate = candidates[i];
            temp.add(candidate);
            // residue - cadidate是剩余的数，pos为i，表示下一次循环还可以重复使用当前的数
            backtrack(ans, temp, residue - candidate, i, candidates);
            temp.remove(temp.size() - 1);
        }
    }

```
