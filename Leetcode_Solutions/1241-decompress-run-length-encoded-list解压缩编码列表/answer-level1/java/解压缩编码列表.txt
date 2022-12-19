```
class Solution {
    public int[] decompressRLElist(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < nums.length / 2; i++) {
            for (int j = 0; j < nums[i * 2]; j++) {
                ans.add(nums[i * 2 + 1]);
            }
        }
        
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}
```
