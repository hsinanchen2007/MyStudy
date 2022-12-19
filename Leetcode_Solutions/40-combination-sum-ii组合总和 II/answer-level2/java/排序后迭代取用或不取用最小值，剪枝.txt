执行结果：
通过
显示详情
执行用时 :
7 ms
, 在所有 Java 提交中击败了
77.78%
的用户
内存消耗 :
40.9 MB
, 在所有 Java 提交中击败了
66.20%
的用户
```
class Solution {
    List<List<Integer>> res = new ArrayList<List<Integer>>();
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        
        if(candidates.length==0)return res;
        Arrays.sort(candidates);
        int len = candidates.length;
        int newend = len-1;
        for(int i=len-1; i>=0; i--){
            if(candidates[i]>target){
                newend=i-1;
            }
        }
        if(newend<0)return res;
        comb(candidates,target,0,newend,new ArrayList<Integer>(),false);
        return res;
    }
    private void comb(int[] nums,int target,int start, int end, List<Integer> list,boolean emp){
        if(target<nums[start]){
            return;
        }
        if(target==nums[start]){
            List<Integer> newl = new ArrayList<Integer>();
            
            newl.addAll(list);
            newl.add(target);
            res.add(newl);
            return;
        }
        if(start==end)return;
        
        comb(nums,target,start+1,end,list,true);
        
        if(emp&& start-1>=0 && nums[start]==nums[start-1]){
            //1,0 in other branch, this is 0.1, so avoid
        }else{
            List<Integer> newl = new ArrayList<Integer>();
            newl.addAll(list);
            newl.add(nums[start]);
            comb(nums,target-nums[start],start+1,end,newl,false);
        }
    }
}
```
