
```
public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> re = new LinkedList<>();
        LinkedList<Integer> list = new LinkedList<>();
        for(int i = 0; i < candidates.length; i++){
            if(candidates[i] <= target){
                list.push(candidates[i]);
                findNext(re, target,candidates[i], candidates, i, list);
                list.pop();
            }
        }
        return re;
    }
    private void findNext(List<List<Integer>> re, int target, int sum, int[] candidates, int i, LinkedList<Integer> mlist){
        if(sum == target){
            LinkedList<Integer> list = new LinkedList<>(mlist);
            re.add(list);
        }else if(sum < target){
            //只向后搜索，不会产生重复
            for(int j = i; j < candidates.length; j ++){
                mlist.push(candidates[j]);
                findNext(re, target, sum + candidates[j],candidates, j, mlist);
                mlist.pop();
            }
        }
    }
```
