### 解题思路
回溯法

1.先排序
2.递归去找符合条件的组合。每次递归需要当前开始的index、当前list的和、当前list
3.每次递归判断当前和是否和target相等，是的话加入结果集。
4.循环数组，判断当前和加上当前元素是否超过target，是的话直接退出。
5.当前list加上当前元素，当前和加上当前元素，开始index往后移1，递归调用。
6.去重用hashset

### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> l = new ArrayList();
        if(candidates==null || candidates.length==0) {
            return l;
        }
        Arrays.sort(candidates);
        
        dfs(candidates, target, l, new ArrayList(), 0, 0);
        
        HashSet<List<Integer>> h = new HashSet(l);
        l=new ArrayList<>(h);
        
        return l;
    }
    
    private void dfs(int[] candidates, int target, List<List<Integer>> l, List<Integer> r, int pos, int sum) {
        if(sum==target) {
            l.add(new ArrayList(r));
            return;
        }
       
        
        for(int i=pos;i<candidates.length;i++) {
            
            if(sum+candidates[i]>target) {
                break;
            }
            
            r.add(candidates[i]);
            
            dfs(candidates, target, l, r, i+1, sum+candidates[i]);
            
            r.remove(r.size()-1);
        }
    }
}
```