- 用HashMap记录遍历过的节点
- Key是格子的index，value是上一步的跳跃单位的集合
```
class Solution {
    public boolean canCross(int[] stones) {
        if (stones.length == 1) return true;
        if (stones[1] != 1) return false;
        HashMap<Integer, HashSet<Integer>> memo= new HashMap<>();
        for (int x : stones) 
            memo.put(x, new HashSet<>());    
        return helper(memo, stones[stones.length-1], 1, 1);
    }

    public boolean helper(HashMap<Integer, HashSet<Integer>> memo, int n, int cur, int pre_k){
        if (cur == n) return true;
        if (memo.containsKey(cur) && memo.get(cur).contains(pre_k)) return false;

        for (int i = pre_k - 1; i <= pre_k + 1; i++){
            if (i == 0) continue;
            if (memo.containsKey(cur+i)){
                if (helper(memo, n, cur + i, i)) return true;
                memo.get(cur+i).add(i);
            }
        }
        return false;
    }
}
```
