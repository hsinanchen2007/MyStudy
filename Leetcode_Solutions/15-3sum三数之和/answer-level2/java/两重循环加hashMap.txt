class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        //排序
        //特殊处理全为零的情况
        //用两重循环加HashMap
        //去重
        Arrays.sort(nums);
        if (nums.length < 3) {
            return new ArrayList<>();
        }
        
        if (nums[0] == 0 && nums[nums.length - 1] == 0) {
            List<List<Integer >>  res =  new ArrayList<>();
            res.add(Arrays.asList(0, 0, 0));
            return res;
        }
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        List<List<Integer >>  ans =  new ArrayList<>();
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int target = 0 - nums[i] - nums[j];
                boolean flag = map.containsKey(target);
                if (flag == true) {
                    ans.add(Arrays.asList(nums[i], nums[j] ,target));
                }
            }
            map.put(nums[i],i);
        }
        Set set = new HashSet<>(ans);
        ans.clear();
        ans.addAll(set);
        return ans;
    }
}