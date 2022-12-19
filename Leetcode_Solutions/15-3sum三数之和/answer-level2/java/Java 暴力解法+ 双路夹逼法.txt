```
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        // 暴力解题法 三层 for 循环 但是超时
        // Arrays.sort(nums);
        // Set<List<Integer>> result =new LinkedHashSet<List<Integer>>();
        // int n = nums.length;
        // for (int i = 0; i < n-2 ;i++) {
        //     for (int j = i+1;j < n-1;j++) {
        //         for (int k = j+1; k < n;k++) {
        //             if (nums[i]+nums[j]+nums[k] == 0){
        //                 List<Integer> tmpList = new ArrayList<>();
        //                 tmpList.add(nums[i]);
        //                 tmpList.add(nums[j]);
        //                 tmpList.add(nums[k]);
        //                 result.add(tmpList);
        //             }
        //         }
        //     }
        // }
        // return new ArrayList(result);

        // 双路夹逼法 + 注意用 LinkedList +   if (i == 0 || i > 0  && nums[i] != nums[i-1]) 这个省去了return 的逻辑
        Arrays.sort(nums);
        List<List<Integer>> result =new LinkedList<>();
        for (int i = 0 ; i < nums.length; i++) {
            if (i == 0 || i > 0  && nums[i] != nums[i-1]){
                int l = i + 1, r = nums.length-1;
                while (l < r) {
                    int total = nums[l] + nums[r] + nums[i];
                    if (total == 0) {
                        result.add(Arrays.asList(nums[i],nums[l],nums[r]));
                        while (l < r && nums[l] == nums[l+1]) l++;
                        while (l < r && nums[r] == nums[r-1]) r--;
                        l++;
                        r--;
                    } else if (total < 0) {
                        l++;
                    }else {
                        r--;
                    }
                }
            }
        }
        return result;
    }
}
```
