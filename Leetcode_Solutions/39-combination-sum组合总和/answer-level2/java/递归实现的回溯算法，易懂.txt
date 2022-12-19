```
class Solution {
private List<List<Integer>> res = new ArrayList<>();
public List<List<Integer>> combinationSum(int[] candidates, int target) {
Stack<Integer> stack = new Stack<>();
search(candidates,stack,target,0);
return res;
}

private void search(int[] candidates,Stack<Integer> stack, int target, int count){
    if(count == target){
        List<Integer> r = new ArrayList<>();
        for(Integer i: stack){
            r.add(i);
        }
        res.add(r);
        return;
    }else if(count < target){
        for(int i = 0; i<candidates.length ; i++){
            //限制候选数字不能比栈顶的数字小,避免重复
            if(!stack.empty() && stack.peek()>candidates[i])
                continue;
            stack.push(candidates[i]);
            count += candidates[i];
            search(candidates,stack,target,count);
            stack.pop();
            count -= candidates[i];
        }
        return;
    }else{
        return;
    }
}
}

```
