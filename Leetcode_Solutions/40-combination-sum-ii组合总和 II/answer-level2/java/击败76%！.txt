### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<List<Integer>> ret = new ArrayList<>(); 
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        if(candidates.length == 0){
            return ret;
        }
        // 将数组排序,这样可以避免重复
        Arrays.sort(candidates);
        List<Integer> already = new ArrayList<>();
        backtracking(already, candidates, 0, target);
        return ret;
    }
    private void backtracking(List<Integer> already, int[] candidates, int start, int target){
        if(target == 0){
            ret.add(new ArrayList<>(already));
            return;
        }
        // 起点已走到尽头
        if(start == candidates.length){
            return;
        }
        for(int i = start; i < candidates.length; i++){
            if(candidates[i] <= target){
                // 之前加过了
                if(i > start && candidates[i] == candidates[i-1]){
                    continue;
                }
                already.add(candidates[i]);
                backtracking(already, candidates, i+1, target - candidates[i]);
                already.remove(already.size() - 1);          
            }
        }
        return;
    }
}
```