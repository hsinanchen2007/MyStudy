### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> results = new ArrayList<>();
        if(k == 0 || n == 0){
            return results;
        }

        int[] nums = new int[9];
        for (int i = 0; i < nums.length; i++) {
            nums[i] = i + 1;
        }

        dfs(nums, 0, new ArrayList<>(), results, k, n);
        return results;
    }

    private void dfs(int[] nums, int index, List<Integer> subsets, List<List<Integer>> results, int k, int n){
        if(k == 0 && n == 0){
            results.add(new ArrayList<>(subsets));
        }

        for (int i = index; i < nums.length; i++) {
            //剪枝
            if(n < nums[i]){
                break;
            }
            subsets.add(nums[i]);
            dfs(nums, i + 1, subsets, results, k - 1, n - nums[i]);
            subsets.remove(subsets.size() - 1);
        }
    }
}
```