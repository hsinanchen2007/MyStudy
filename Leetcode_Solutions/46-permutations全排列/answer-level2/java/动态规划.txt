```
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> dp = new ArrayList(new ArrayList<Integer>());
        List<Integer> list = new ArrayList<Integer>();
        list.add(nums[0]);
        dp.add(list);
        if(nums.length == 1) return dp;
        else return permute(dp, nums, 1);
    }
    public List<List<Integer>> permute(List<List<Integer>> dp, int[] nums, int n){
        if(nums.length == n) return dp;
        int num = nums[n];
        List<List<Integer>> tmp = new ArrayList<>();
        for(int i = 0; i < dp.size(); i++){
            List<Integer> li = dp.get(i);
            for(int j = 0; j <= n; j++){
                List<Integer> l = new ArrayList<Integer>(li);
                l.add(j, nums[n]);
                tmp.add(l);
            }        
        }
        return permute(tmp, nums, n + 1);
    }  
}
```
