```
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> results = new ArrayList<>();
        if (nums == null) {
            return results;
        }

        if (nums.length == 0) {
            return results;
        }

        Arrays.sort(nums);
        dfs(nums, 0, new ArrayList<>(), results, 4, target);

        return results;
    }

    private void dfs(int[] nums, int index, List<Integer> subsets, List<List<Integer>> results, int k, int target) {
        if (k == 0 && target == 0) {
            results.add(new ArrayList<>(subsets));
        }

        for (int i = index; i < nums.length; i++) {
            if(i > index && nums[i] == nums[i - 1]) continue;
            subsets.add(nums[i]);
            dfs(nums, i + 1, subsets, results, k - 1, target - nums[i]);
            subsets.remove(subsets.size() - 1);
        }
    }
}
```
