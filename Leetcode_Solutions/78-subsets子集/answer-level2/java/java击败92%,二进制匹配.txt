```
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        int length = 1 << nums.length;
        for(int i = 0 ; i < length ; i++) {
            List<Integer> list = new ArrayList<>();
            for(int j = 0 ; j < nums.length ; j++) {
                if(((1 << j) & i) != 0){
                    list.add(nums[j]);
                }
            }
            res.add(list);
        }
        return res;
    }
}
```
