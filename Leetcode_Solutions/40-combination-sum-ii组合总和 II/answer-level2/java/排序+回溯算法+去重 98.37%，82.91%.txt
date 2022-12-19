### 解题思路
排序+回溯算法+去重

### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result=new ArrayList<>();
        if(candidates==null||candidates.length==0){
            return result;
        }

        //排序
        Arrays.sort(candidates);
        boolean[] used=new boolean[candidates.length];
        Arrays.fill(used,false);
        helper(candidates,target,0,result,new ArrayList<Integer>(),0,used);

        return result;
    }

    public void helper(int[] candidates,int target,int temp,List<List<Integer>> result,ArrayList<Integer> list,int i,boolean[] used){
        if(target==temp){
            result.add(new ArrayList<Integer>(list));
            return;
        }
        
        if(i<candidates.length&&temp+candidates[i]<=target){
            //去重
            while(i>0&&i<candidates.length&&!used[i-1]&&candidates[i]==candidates[i-1]){
                i++;
            }
            if(i==candidates.length||temp+candidates[i]>target){
                return;
            }
            ArrayList<Integer> listtemp=new ArrayList<Integer>(list);
            list.add(candidates[i]);
            used[i]=true;
            helper(candidates,target,temp+candidates[i],result,list,i+1,used);//加i
            used[i]=false;
            helper(candidates,target,temp,result,listtemp,i+1,used);//不加i

        }
    }
}
```