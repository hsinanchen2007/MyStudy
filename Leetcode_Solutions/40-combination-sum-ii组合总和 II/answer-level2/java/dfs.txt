### 解题思路
dfs
排序
统计该字符出现个数
循环中每次加一个该字符，后面得字符必不是该字符的dfs

### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        dfsFind(candidates,target,0,stack,ans);
        return ans;
    }
    private void dfsFind(int[] candidates, int target,int idx,Stack<Integer> stack,List<List<Integer>> ans) {
        if(target==0 && idx<=candidates.length){
            List<Integer> list = new ArrayList<>(stack.size());
            list.addAll(stack);
            ans.add(list);
            return;
        }
        if(idx>=candidates.length){
            return;
        }

        if(target<0){
            return;
        }

        int count = 1;
        while (idx+1<candidates.length && candidates[idx] == candidates[idx+1]){
            idx++;
            count++;
        }
        dfsFind(candidates,target,idx+1,stack,ans);

        for(int i=1;i<=count;i++){
            if(candidates[idx]*i<=target){
                stack.push(candidates[idx]);
                dfsFind(candidates,target-candidates[idx]*i,idx+1,stack,ans);
            }
        }

        for(int i=1;i<=count;i++){
            if(candidates[idx]*i<=target){
                stack.pop();
            }
        }
    }
}
```