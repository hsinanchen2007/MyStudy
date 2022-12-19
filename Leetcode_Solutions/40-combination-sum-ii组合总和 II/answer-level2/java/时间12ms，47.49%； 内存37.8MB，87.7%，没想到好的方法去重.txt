 * 1. 看到别人的剪枝使用的是每一层都是for循环，然后可以每一层剪枝，隔层的不比剪，这就是116可以但是116和116不行。关键在于index是否有增加。
 * 只要深度有增加，就可以重复。，是符合条件的。这个结合那个剪枝图看更好理解。但是自己这种方法没办法。因为自己是深度优先，不是广度优先。
 * 2. 从复杂度上看，每层都for循环的是n!, 但是自己的是2^n,

```
/**
     * 1. 题目基本和上一题一直，只不过这里变成了每个数字只能用一次，而且给的数组不一定是没有重复数字。
     * 2. 每个数字只能用一次很好办，直接加个计数器即可。但是去重比较麻烦，自己在获得结果之后进行的去重。感觉不是很好的方法。
     * 3. 时间12ms，47.49%； 内存37.8MB，87.7%
     * 
     * 
     * @Author kaikai 2019年10月4日 下午8:56:13
     * @param candidates
     * @param target
     * @return
     */
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        // 排序
        Arrays.sort(candidates);
        combinationSumHelp2(result, new ArrayList<Integer>(), candidates, target, 0, 0);

        Set<String> set = new HashSet<String>();
        Iterator iter = result.iterator();
        while (iter.hasNext()) {
            List<Integer> temp = (List<Integer>) iter.next();
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < temp.size(); i++) {
                sb.append(temp.get(i));
            }
            if (set.contains(sb.toString())) {
                iter.remove();
            } else {
                set.add(sb.toString());
            }

        }
        return result;
    }

    public void combinationSumHelp2(List<List<Integer>> result, List<Integer> nowList, int[] candidates, int target,
            int index, int amount) {
        // 剪枝
        if (index >= candidates.length || candidates[index] > target || candidates[index] + amount > target) {
            return;
        }
        List<Integer> beforeList;
        int countNum = 0;
        while (amount <= target) {
            if (amount == target) {
                result.add(nowList);
                return;
            }
            beforeList = new ArrayList<Integer>(nowList);
            combinationSumHelp2(result, nowList, candidates, target, index + 1, amount);
            if (countNum > 0) {
                break;
            }
            nowList = beforeList;
            nowList.add(candidates[index]);
            amount = amount + candidates[index];
            countNum++;

        }
    }
```
