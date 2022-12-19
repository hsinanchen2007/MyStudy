### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum2(int[] nums, int target) {
        List<List<Integer>> results = new ArrayList<>();
        if (nums == null) {
            return results;
        }
        if (nums.length == 0) {
            results.add(new ArrayList<>());
            return results;
        }

        Arrays.sort(nums);
        dfs(nums, 0, new ArrayList<>(), results, target);

        return results;
    }

    //当然也可以使用sum(nums)来判断和是否等于target，但是传参target更好
    private void dfs(int[] nums, int index, List<Integer> subsets, List<List<Integer>> results, int target) {
        if(target == 0){
            results.add(new ArrayList<>(subsets));
        }

        for (int i = index; i < nums.length; i++) {
            if(target < nums[i]){
                break;
            }
            if(i > index && nums[i] == nums[i - 1]) continue;
            subsets.add(nums[i]);
            dfs(nums, i + 1, subsets, results, target - nums[i]);
            subsets.remove(subsets.size() - 1);
        }
    }
}
```