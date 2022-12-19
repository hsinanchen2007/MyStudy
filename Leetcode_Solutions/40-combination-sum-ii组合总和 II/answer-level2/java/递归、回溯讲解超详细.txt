本题和39题解法大致一致，关于递归、回溯的套路可参考[递归、回溯的一些套路](https://leetcode-cn.com/circle/article/GV6eQ2/)
有区别的是，本题的数只能使用一次。因此遍历的时候，每次的start应该为i+1,并且在遍历时需要做一个判重。具体见代码
```
List<List<Integer>> lists = new ArrayList<>();

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        if (candidates == null || candidates.length == 0 || target < 0) {
            return lists;
        }
        Arrays.sort(candidates);
        List<Integer> list = new ArrayList<>();
        process(0, candidates, target, list);
        return lists;
    }

    private void process(int start, int[] candidates, int target, List<Integer> list) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            lists.add(new ArrayList<>(list));
        } else {
            for (int i = start; i < candidates.length; i++) {
                //因为这个数和上个数相同，所以从这个数开始的所以情况，在上个数里面都考虑过了，需要跳过
                if (i > start && candidates[i] == candidates[i - 1]) {
                    continue;
                }

                list.add(candidates[i]);
                process(i + 1, candidates, target - candidates[i], list);
                list.remove(list.size() - 1);
            }
        }

    }
```
