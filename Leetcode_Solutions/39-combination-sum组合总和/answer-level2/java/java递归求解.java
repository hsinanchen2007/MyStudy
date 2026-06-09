
```
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);//先排序
        List<List<Integer>> result=new ArrayList<List<Integer>>();
        if(target<candidates[0])
            return result;
        fun(candidates,0,target,new ArrayList<Integer>(),result);
        return result;
    }

    public void fun(int[] a,int f,int target,List<Integer> list,List<List<Integer>> result){
        if(target<0||f>=a.length)
            return;
        else if(target==0){
            result.add(list);//得到一个答案
            return;
        }
        else{
            if(a[f]<=target){
                List<Integer> l1=new ArrayList<Integer>(list);
                l1.add(a[f]);
            fun(a,f,target-a[f],l1,result);//取a[f]且重复取
            //fun(a,f+1,target-a[f],l1,result);//不重复取，这种情况已经被其他2个包含进去
            fun(a,f+1,target,list,result);//不取a[f]
        }
        else return;
        }
     
    }
}
```