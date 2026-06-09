### 解题思路
此处撰写解题思路
回溯模板，帅爆了
执行用时 :
3 ms
, 在所有 Java 提交中击败了
94.46%
的用户
内存消耗 :
39.6 MB
, 在所有 Java 提交中击败了
12.59%
的用户
### 代码

```java
class Solution {
    private List<List<Integer>> res;
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        res = new ArrayList<>();
        LinkedList<Integer> track = new LinkedList<>();
        Arrays.sort(candidates);
        backtrack(candidates, 0, target, track);
        return res;    
    }
    private void backtrack(int[] candidates, int start, int target, LinkedList<Integer> track){
        if (target < 0) return;
        if (target == 0){
            res.add(new LinkedList<>(track));
            return;
        }
        for( int i = start; i < candidates.length; i++){
            if (target < candidates[i]) break;
            track.add(candidates[i]);
            backtrack(candidates, i, target - candidates[i], track);
            track.removeLast();
        }
    }
}
```