```
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if(nums==null||nums.length<1){
            return result;
        }
        if(nums.length==1){
            List<Integer> one = new ArrayList<>();
            one.add(nums[0]);
            result.add(one);
        }else{
            permute(result,nums, new ArrayList<Integer>());
        }
        return result;
        
    }
    
    private void permute(List<List<Integer>> result, int[] candidates, List<Integer> curr){
        if(candidates.length==0){
            result.add(new ArrayList<Integer>(curr));
        }else{
            for(int i = 0;i<candidates.length;i++){
                curr.add(candidates[i]);
                permute(result,removeElement(candidates,i),curr);
                curr.remove(curr.size()-1);
            }
        }
        
    }
    
    private int[] removeElement(int[] array, int index){
        int[] subArray = new int[array.length-1];
        int subArrI = 0;
        for(int i = 0;i<array.length;i++){
            if(i==index){
                continue;
            }
            subArray[subArrI++] = array[i];
            
        }
        return subArray;
    }
}
```
