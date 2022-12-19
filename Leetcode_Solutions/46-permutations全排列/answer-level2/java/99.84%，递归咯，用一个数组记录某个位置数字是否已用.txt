```
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        // 递归递归
        List<List<Integer>> r = new ArrayList<>();
        boolean[] used = new boolean[nums.length];
        h(new ArrayList<>(), r, nums, used);
        return r;
    }

    private void h(List<Integer> c, List<List<Integer>> r, int[] nums, boolean[] used) {
        if(c.size() == nums.length) {
            r.add(new ArrayList<>(c));
            return;
        }

        for(int i = 0; i < nums.length; ++ i) {
            if(!used[i]) {
                used[i] = true;
                c.add(nums[i]);
                h(c, r, nums, used);
                c.remove(c.size() - 1);
                used[i] = false;
            }
        }
    }
}
```
