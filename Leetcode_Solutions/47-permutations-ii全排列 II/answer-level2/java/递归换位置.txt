
[全排列1](https://leetcode-cn.com/problems/permutations/solution/huan-wei-zhi-by-mrliu0635/)
仅仅改动一丢丢，只需要增加一个标志位，用于**检查替换是否有意义**，**去掉无意义的替换**。
```
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
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
        HashSet<Integer> h = new HashSet<Integer>();
        h.add(nums[s]);
        for(int i = s + 1;i < nums.length;i++) {
            if (h.contains(nums[i])) continue;
            h.add(nums[i]);
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
