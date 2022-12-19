```
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res=new ArrayList<List<Integer>>();
        Arrays.sort(candidates);
        if(target<candidates[0])
            return res;
        backTrack(candidates,0,target,res,new ArrayList<Integer>());
        //结果可能包含相同的序列，借助set去重
        Set<List<Integer>> set=new HashSet<>(res);
        res=new ArrayList<>(set);
        return res;
        
    }
    //回溯法
    public void backTrack(int[] a,int f,int target,List<List<Integer>> res,List<Integer> temp){
        if(target==0){
            res.add(new ArrayList<Integer>(temp));
            return;
        }
        for(int i=f;i<a.length;i++){
            if(a[i]<=target){
                temp.add(a[i]);
                backTrack(a,i+1,target-a[i],res,temp);
                temp.remove(temp.size()-1);
            }
            else return;
        }
    }
}
```