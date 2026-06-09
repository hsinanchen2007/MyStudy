和组合数I思路基本一致，如果没办法看懂代码的可以去看看上道题我写的题解。
链接如下：
https://leetcode-cn.com/problems/combination-sum/solution/jian-dan-di-gui-si-lu-by-sky-137/

```
class Solution {
    public static List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> currentAns = new ArrayList<>();
        if(candidates.length == 0)
            return ans;
        Arrays.sort(candidates);
        for (int i = 0; i < candidates.length && candidates[i] <= target;) {
            getList(ans,currentAns,candidates,i,target);
            i++;
            while(i<candidates.length && candidates[i] == candidates[i-1])
                i++;
        }
        return ans;
    }
    private static void getList(List<List<Integer>> ans,List<Integer> currentAns, int [] candidates, int i, int res){
        currentAns.add(candidates[i]);
        res -= candidates[i];
        if(res == 0){
            ans.add(new ArrayList<>(currentAns));
        }
        i++;
        while(i < candidates.length && candidates[i] <= res){
            getList(ans,currentAns,candidates,i,res);
            i++;
            while(i < candidates.length && candidates[i] == candidates[i-1])
                i++;
        }
        currentAns.remove(currentAns.size()-1);
    }
}
```
