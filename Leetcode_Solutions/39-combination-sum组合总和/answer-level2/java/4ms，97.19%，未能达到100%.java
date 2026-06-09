 * 1. 有的题解使用的是减法回溯，这是自己没有想到的
 * 2. 发现有的题解提到了如何去重。很多使用排序。自己是使用的index。
 * 3. 其实一开始自己感觉和完全背包很像。但是背包好像是找到最优解，不是全部解。

```
/**
     * 1. 时间12ms，击败42.71%，内存38MB，击败94.21%
     * 2. 还是回溯。不过这次结束条件还有index超出范围，也就是结束条件要么是找到目标，要么超出index。而至于这一次递归做什么以及递归状态的保持需要仔细分析情况。
     * 3. 还有一点很重要，就是一定要先递归，后操作。因为可以不取当下的值
     * 
     * @Author kaikai 2019年10月4日 下午6:25:24
     * @param candidates
     * @param target
     * @return
     */
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();

        combinationSumHelp(result, new ArrayList<Integer>(), candidates, target, 0, 0);

        return result;
    }

    public void combinationSumHelp(List<List<Integer>> result, List<Integer> nowList, int[] candidates, int target,
            int index, int amount) {
        if (index >= candidates.length) {
            return;
        }
        List<Integer> beforeList;
        while (amount <= target) {
            if (amount == target) {
                result.add(nowList);
                return;
            }
            beforeList = new ArrayList<Integer>(nowList);
            combinationSumHelp(result, nowList, candidates, target, index + 1, amount);
            nowList = beforeList;
            nowList.add(candidates[index]);
            amount = amount + candidates[index];

        }
    }

    /**
     * 1. 增加剪枝：时间4ms，击败97.19，内存37.2，击败96.94
     * 2. 相比于第一种方法，主要的改进是排序，而后剪枝。
     * 
     * @Author kaikai 2019年10月4日 下午6:32:27
     * @param candidates
     * @param target
     * @return
     */
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        // 排序
        Arrays.sort(candidates);
        combinationSumHelp2(result, new ArrayList<Integer>(), candidates, target, 0, 0);

        return result;
    }

    public void combinationSumHelp2(List<List<Integer>> result, List<Integer> nowList, int[] candidates, int target,
            int index, int amount) {
        // 剪枝
        if (index >= candidates.length || candidates[index] > target || candidates[index] + amount > target) {
            return;
        }
        List<Integer> beforeList;
        while (amount <= target) {
            if (amount == target) {
                result.add(nowList);
                return;
            }
            beforeList = new ArrayList<Integer>(nowList);
            combinationSumHelp2(result, nowList, candidates, target, index + 1, amount);
            nowList = beforeList;
            nowList.add(candidates[index]);
            amount = amount + candidates[index];

        }
    }
```
