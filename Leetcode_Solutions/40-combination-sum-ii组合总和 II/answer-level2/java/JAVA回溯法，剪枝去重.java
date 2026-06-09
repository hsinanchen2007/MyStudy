
由于数组中有重复元素，所以在每一次进行下一次回溯前要检查，这一层级的回溯所使用的元素，有没有在循环中使用过了
体现到代码里就是已经排好序的nums，如果有nums[1,1,1,1,1,1,2,3,4,5] target 6
当i等于0的时候用1作为下一层级的数组元素没关系，而i等于1的时候的这个1在进行下一层级搜索组合的时候就和之前的1冲突了
这里的剪枝只针对当前层级里出现的重复元素，不同层级的重复元素已经被回溯递归时候的i+1排除掉了。

剪枝后的速度
2ms 100%
```
class Solution {
    List<List<Integer>> ans = new ArrayList();
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        backtracking(candidates,0,target,new ArrayList());
        return ans;
    }

    public void backtracking(int[] nums,int start,int target,List<Integer> list){
        if(target == 0){
            ans.add(new ArrayList(list));
            return;
        }
        for(int i = start; i < nums.length; i++){
            if(i>start && nums[i]==nums[i-1])continue;
            if(nums[i] > target){
                return;
            }else{
                list.add(nums[i]);
                backtracking(nums,i+1,target-nums[i],list);
                list.remove(list.size()-1);
            }
        }
        return;
    }       
}

```

剪枝前使用hashset暴力去重
6-9ms  40-50%
```
class Solution {
    Set<List<Integer>> ans = new HashSet();
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        backtracking(candidates,0,target,new ArrayList());
        return new ArrayList(ans);
    }

    public void backtracking(int[] nums,int start,int target,List<Integer> list){
        if(target == 0){
            List<Integer> temp = new ArrayList(list);
            Collections.sort(temp);
            ans.add(new ArrayList(temp));
            return;
        }
        for(int i = start; i < nums.length; i++){
            if(nums[i] > target){
                return;
            }else{
                list.add(nums[i]);
                backtracking(nums,i+1,target-nums[i],list);
                list.remove(list.size()-1);
            }
        }
        return;
    }       
}
```

