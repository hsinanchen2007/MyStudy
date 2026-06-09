### 解题思路
暴力法：回溯+去重
思路：把所有的解求出在回溯外部去重

### 代码
```java 
class Solution {

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        if(candidates == null || candidates.length == 0){
            return result;
        }
        Arrays.sort(candidates);
        for (int candidate : candidates) {
            List<Integer> selected = new ArrayList<>();
            selected.add(candidate);
            combination(result, selected, candidates, target - candidate);
        }
        return result;
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> tempResult = new ArrayList<>();
        if(candidates == null || candidates.length == 0){
            return tempResult;
        }
        for (int candidate : candidates) {
            List<Integer> selected = new ArrayList<>();
            selected.add(candidate);
            combination(tempResult, selected, candidates, target - candidate);
        }
        List<List<Integer>> result = new ArrayList<>();
        for(List<Integer> r : tempResult){
            if(result.isEmpty()){
                result.add(r);
            } else {
                boolean flag = false;
                for(List<Integer> comfirmed: result){
                    if (isSameList(comfirmed, r)) {
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    result.add(r);
                }
            }
        }
        return result;
    }

    private boolean isSameList(List<Integer> src,List<Integer> target){
        if(src.size() != target.size()){
            return false;
        }
        Collections.sort(src);
        Collections.sort(target);
        for(int i = 0;i<src.size();i++){
            if(!src.get(i).equals(target.get(i))){
                return false;
            }
        }
        return true;
    }

    private void combination(List<List<Integer>> result,List<Integer> selected,int[] candidates,int target){
        if(target == 0){
            result.add(selected);
        } else if(target < 0){
            return;
        }
        for (int candidate : candidates) {
            List<Integer> s = new ArrayList<>(selected);
            s.add(candidate);
            combination(result, s, candidates, target - candidate);
        }
    }

}
```

### 解题思路
重复的解是如何产生的？
题目没有限制我们选取数字，但是选取比自身小的数求解，求出的解集合必然包含在对应小数为起点求解的解集中，所以在回溯的过程中可以限制选择那些小于自身的数求解。那么解题优化思路就呼之欲出了。

剪枝法：回溯+剪枝
思路：在回溯内部通过剪枝去掉重复解。

代码比暴力法简洁太多了。


### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        if(candidates == null || candidates.length == 0){
            return result;
        }
        for (int candidate : candidates) {
            List<Integer> selected = new ArrayList<>();
            selected.add(candidate);
            combination(result, selected, candidates, target - candidate);
        }
        return result;
    }

    private void combination(List<List<Integer>> result, List<Integer> selected, int[] candidates, int target){
        if(target == 0){
            result.add(selected);
        } else if(target < 0){
            return;
        }
        int limit = selected.get(selected.size() - 1);
        for (int candidate : candidates) {
            if(candidate >= limit){
                List<Integer> s = new ArrayList<>(selected);
                s.add(candidate);
                combination(result, s, candidates, target - candidate);
            }
        }
    }
}
```