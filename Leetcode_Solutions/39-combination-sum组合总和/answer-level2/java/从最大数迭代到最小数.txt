执行结果：
通过
显示详情
执行用时 :
12 ms
, 在所有 Java 提交中击败了
46.90%
的用户
内存消耗 :
42.4 MB
, 在所有 Java 提交中击败了
63.92%
的用户
```
class Solution {
    List<List<Integer>> res = new ArrayList<List<Integer>>();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<Integer> temp = new ArrayList<Integer>();
        if(target==0||candidates.length==0||target<candidates[0])return res;
        get(candidates,target,candidates.length-1,temp);
        return res;
        
    }
    
    private void get(int[] nums, int left, int end, List<Integer> temp  ){
        if(left<nums[0])return;
        if(end<0)return;
        int iend=nums[end];
        int div = left/iend;
        
        
        get(nums,left,end-1,temp);
        
        for(int i=1; i<=div; i++){
            List<Integer> list=new ArrayList<Integer>(temp.size()<<1);
            for(int j=i; j>0; j--){
                list.add(iend);
            }
            list.addAll(temp);
            int newleft = left-i*iend;
            if(newleft==0){
                res.add(list);
            }else{
                get(nums,newleft,end-1,list);
            }

        }
        
        
    }
}
```
代码块
```
```
