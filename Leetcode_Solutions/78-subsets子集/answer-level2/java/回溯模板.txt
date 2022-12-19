### 解题思路
回溯模板

### 代码

```java
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        if (nums == null || nums.length == 0)
            return res;
        Arrays.sort(nums);
        res.add(new ArrayList<>());
        backtrack(nums, 0, res, temp);
        return res;
    }

    private void backtrack(int[] nums, int start, List<List<Integer>> res, List<Integer> temp) {
        if (start > nums[nums.length - 1]) {
            return;
        }
        for (int i = start; i < nums.length; i++) {
            temp.add(nums[i]);
            res.add(new ArrayList<>(temp));
            backtrack(nums, i + 1, res, temp);
            temp.remove(temp.size() - 1);
        }
    }
}
```