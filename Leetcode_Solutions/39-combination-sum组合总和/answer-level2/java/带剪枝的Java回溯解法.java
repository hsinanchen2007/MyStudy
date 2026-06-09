剪枝：先对数组进行排序，当前递归中如果值大于要找的target，则直接结束。因为后面的值更大，不可能满足要求。
```
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> resultList = new ArrayList<>();
        if(candidates.length == 0){
            return resultList;
        }
        Arrays.sort(candidates);
        combinationSum(resultList,new ArrayList<>(),candidates,target,0);
        return resultList;
    }
    private void combinationSum(List<List<Integer>> resultList,List<Integer> currentList,int[] candidates,int target,int index){
        if(target == 0){
            resultList.add(new ArrayList<>(currentList));
            return;
        }
        for(int i = index;i < candidates.length;i++){
            if(candidates[i] > target){
                break;
            }
            currentList.add(candidates[i]);
            combinationSum(resultList,currentList,candidates,target - candidates[i],i);
            currentList.remove(currentList.size() - 1);
        }
    }
}
```
