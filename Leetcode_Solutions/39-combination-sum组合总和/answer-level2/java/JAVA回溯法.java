这一题很容易可以想到回溯法，不过我一开始没有想到剪枝的条件，对于重复的元祖我直接使用了暴力的set和排序
我原本以为剪枝条件会很刁钻，后来参考了别人的代码后发现玄机就在排序中，对于回溯法中可能会碰到的2,2,3  2,3,2  3,2,2
这样的重复元素，只要一开始将备选数组排序，并且每次在回溯的时候不要从0开始，
从当前回溯的数开始进行下一轮寻找就可以有效的解决这个问题
因为我们从2开始作为第一个元素进行组合的时候，已经包含了后面所有会出现2的结果。
总结的话语写的可能不是很明朗，这里单纯做个笔记给自己提个醒

未剪枝强行排序去重 30ms
```
class Solution {
    
    Set<List<Integer>> ans = new ArrayList();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        backtracking(candidates,target,new ArrayList());
        return new ArrayList(ans);
    }

    public void backtracking(int[] nums,int target,List<Integer> list){
        if(target == 0){ 
            List<Integer> res = new ArrayList(list);
            Collections.sort(res);
            ans.add(res);
            return;
        }
        for(int i = index; i<nums.length;i++){
            if(target >= nums[i]){
                list.add(nums[i]);
                int next = target-nums[i];
                backtracking(nums,next,list);
                list.remove(list.size()-1);
            }else{
                return;
            }
        }
    }
}
```
剪枝后 2ms
```
class Solution {
    
    List<List<Integer>> ans = new ArrayList();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        backtracking(candidates,target,new ArrayList(),0);
        return ans;
    }

    public void backtracking(int[] nums,int target,List<Integer> list,int index){
        if(target == 0){ 
            List<Integer> res = new ArrayList(list);
            ans.add(res);
            return;
        }
        for(int i = index; i<nums.length;i++){
            if(target >= nums[i]){
                list.add(nums[i]);
                int next = target-nums[i];
                backtracking(nums,next,list,i);
                list.remove(list.size()-1);
            }else{
                return;
            }
        }
    }
}
```
