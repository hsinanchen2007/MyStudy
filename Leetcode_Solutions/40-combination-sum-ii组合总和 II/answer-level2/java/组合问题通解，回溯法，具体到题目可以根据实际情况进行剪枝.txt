执行用时 :3 ms, 在所有 java 提交中击败了99.00% 的用户
内存消耗 :37.4 MB, 在所有 java 提交中击败了89.90%的用户
```
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> AL = new ArrayList();
        if(candidates == null || candidates.length < 1)
            return AL;
        int len = candidates.length;
        Arrays.sort(candidates);
        if(target < candidates[0])
            return AL;
        if(candidates[0] == target){
            List<Integer> list = new ArrayList();
            list.add(candidates[0]);
            AL.add(new ArrayList(list));
            return AL;
        }
        int[] flag = new int[len];
        List<Integer> list = new ArrayList();
        getResult(candidates, flag, 0, 0, target, AL, list);
        return AL;
    }
    public void getResult(int[] candidates, int[] flag, int start, int sum, int target, List<List<Integer>> AL, List<Integer> list){
        if(sum == target){
           AL.add(new ArrayList(list));
           return;
        }
        if(start == candidates.length || sum > target)
            return;
        for(int i = start; i < candidates.length && (sum+candidates[i] <= target); i++){
            if(flag[i] == 0){
                if(i > 0 && candidates[i] == candidates[i-1] && flag[i-1] == 0)
                    continue;
                flag[i] = 1;
                list.add(candidates[i]);
                getResult(candidates, flag, i+1, sum+candidates[i], target, AL, list);
                flag[i] = 0;
                list.remove(list.size()-1);
            }
        }
    }
}
```
