对于无重复的全排列，可以采用换位置的方式
```
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> i = new ArrayList<List<Integer>>();
        permute(nums,0, i);
        return i;
    }
    public void permute(int[] nums, int s, List<List<Integer>> c) {
        if (s == nums.length - 1) {
            List<Integer> a = Arrays.stream(nums).boxed().collect(Collectors.toList());
            c.add(a);
            return;
        }
        permute(nums, s + 1, c);
        for(int i = s + 1;i < nums.length;i++) {
            int t = nums[i];
            nums[i] = nums[s];
            nums[s] = t;
            permute(nums, s + 1, c);
            nums[s] = nums[i];
            nums[i] = t;
        }
    }
}
```
