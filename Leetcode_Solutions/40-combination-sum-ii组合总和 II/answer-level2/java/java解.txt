### 解题思路
在之前上面加了去重

### 代码

```java
class Solution {
    private static List<List<Integer>> res;
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        res = new ArrayList<>();
        if(candidates.length == 0 || candidates == null)
            return res;
        Arrays.sort(candidates);
        List<Integer> list = new ArrayList<>();
        helper(candidates,target,0,list);
        Set<List<Integer>> set = new HashSet<>(res);
        res = new ArrayList<>(set);
        return res;
    }
    public  void helper(int[] candidates,int target,int index,                    List<Integer> list){
        if(target == 0){
            res.add(new ArrayList<>(list));
            return;
        }
        for(int i = index;i < candidates.length && candidates[i] <= target;i++){
            list.add(candidates[i]);
            helper(candidates,target-candidates[i],i+1,list);
            list.remove(list.size()-1);
        }
    }
}
```