class Solution {
    List<List<Integer>> list = new ArrayList<>();

    public List<List<Integer>> permute(int[] nums) {
        dfs(nums, 0, nums.length - 1);
        return list;
    }

    public void dfs(int[] nums, int count, int length) {
        if (count == length) {
            List<Integer> ans = new ArrayList<>();
            for (int i = 0; i < nums.length; i++) {
                ans.add(nums[i]);
            }
            list.add(ans);
        }

        for (int i = count; i <= length; i++) {
            swap(nums, i, count);
            dfs(nums, count + 1, length);
            swap(nums, i, count);
        }
    }

    public void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}