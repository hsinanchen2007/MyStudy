### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<List<Integer>> ret = new ArrayList<>();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if(candidates.length == 0){
            return ret;
        }
        List<Integer> already = new ArrayList<>();
        backtracking(already, candidates, target, 0);
        return ret;
        


    }
    // 之搜寻数组index下标后的数值
    private void backtracking(List<Integer> already, int[] candidates, int target, int index){
        if(target == 0){
            ret.add(new ArrayList<>(already));
            return;
        }
        if(target < 0){
            return;
        }
        for(int i = index; i < candidates.length; i++){
            if(candidates[i] <= target){
                already.add(candidates[i]);
                backtracking(already, candidates, target - candidates[i], i);
                already.remove(already.size() - 1);
            }
        }
        return;
        
    }
}
```