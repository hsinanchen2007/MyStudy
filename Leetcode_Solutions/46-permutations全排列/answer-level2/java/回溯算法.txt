回溯算法，超过100%的用户
```
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        if(nums.length == 0) return list;
        answer(list,nums,0);
        return list;
    }
    private void answer(List list , int[] nums,int start){
        if(start == nums.length-1) {
            List<Integer> newlist = new ArrayList<>();
            for(int i : nums){
                newlist.add(i);
            }
            list.add(newlist);
            return;
        }
        for(int i = start;i<nums.length;i++){
            swap(nums,start,i);
            answer(list,nums,start+1);
            swap(nums,start,i);
        }
    }
    private void swap(int nums[] ,int i ,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```
