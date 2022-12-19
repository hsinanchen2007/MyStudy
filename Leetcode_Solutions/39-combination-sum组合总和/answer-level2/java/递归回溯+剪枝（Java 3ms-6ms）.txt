

``` java 
class Solution {
    private List<List<Integer>> result = new ArrayList<>();

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        generate(candidates,target,0,0,new ArrayList());
        return result;
    }
    private void generate(int[] candidates,int target,int start,int sum,List<Integer> temp){
        if(sum > target){
            return;
        }
        if(sum == target){
            result.add(new ArrayList(temp));
            return;
        }
        for(int i = start; i < candidates.length; i++){
            //剪枝
            if(i>0 && candidates[i] > candidates[i-1] && sum + candidates[i-1] >= target ){
                continue;
            }
            temp.add(candidates[i]);
            sum += candidates[i]; 
            generate(candidates,target,i,sum,temp);
            //回溯
            temp.remove(temp.size()-1);
            sum -= candidates[i];
        }
    }
}
```
