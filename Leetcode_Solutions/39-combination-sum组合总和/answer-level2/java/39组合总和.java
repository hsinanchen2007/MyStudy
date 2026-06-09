回溯算法，深度优先遍历：
```
step1：对数组排序，有利于后面提前结束循环
step2：遍历数组元素：（循环开始指针的引入可以解决重复组合的问题）
    若 target== 0 将当前序列加入结果集中
    若 target < 0 说明这条路径不通，结束当前循环，返回上一层换下一个数继续循环
    若 target > 0 将当前元素压入栈中；更新target和start；递归更深一层的循环；当更深的循环结束后，弹出当前栈顶元素，返回上一层循环
```


```
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Stack<Integer> current = new Stack<Integer>();
        Arrays.sort(candidates);

        helper(candidates, 0, target, result, current);
        return result;
    }

    private void helper(int[] nums, int start, int target, List<List<Integer>> result, Stack<Integer> current)
    {
        if(target==0) 
        {
            if (!result.contains(new ArrayList<>(current)))
                result.add(new ArrayList<>(current)); 
            return;
        }
        //以start为循环开始可以避免重复组合，i要求小于数组长度，且i下标对应的数组值小于target可提取结束循环
        for (int i=start; i<nums.length && nums[i]<=target ; i++)  
        {           
            current.push(nums[i]);
            helper(nums, i, target-nums[i], result, current);
            current.pop();                    
        }     
    }
}
```
