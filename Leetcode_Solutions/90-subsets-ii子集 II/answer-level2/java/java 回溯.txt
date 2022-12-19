```
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        result.add(new ArrayList<Integer>());
        if(nums==null||nums.length<1){
            return result;
        }
        Arrays.sort(nums);
        subset(result,0,nums,new ArrayList<Integer>());
        return result;
    }
    
    private void subset(List<List<Integer>> result, int currIndex, int[] nums,List<Integer> curr){
        
        for(int i = currIndex;i<nums.length;i++){
            if(i!=currIndex&&nums[i]==nums[i-1]){
                continue;
            }
            curr.add(nums[i]);
            result.add(new ArrayList<Integer>(curr));
            subset(result,i+1,nums,curr);
            curr.remove(curr.size()-1);
        }
    }
        
    
}
```
