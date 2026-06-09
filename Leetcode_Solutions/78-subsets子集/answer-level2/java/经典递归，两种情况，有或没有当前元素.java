```
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        // classic recursion, all possibilities
        List<List<Integer>> res = new ArrayList<>();
        h(res, nums, 0, new ArrayList<>());
        return res;
    }

    private void h(List<List<Integer>> answer, int[] nums, int i, List<Integer> sub) {
        if(i == nums.length) {
            answer.add(new ArrayList<>(sub));
            return;
        }

        sub.add(nums[i]);
        h(answer, nums, i + 1, sub);
        sub.remove(sub.size() - 1);

        h(answer, nums, i + 1, sub);
    } 
}
```
