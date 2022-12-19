### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<List<Integer>> results = new ArrayList<>();

    public List<List<Integer>> permute(int[] nums) {
        List<Integer> list = new ArrayList<>();
        if (nums.length == 0) {
            results.add(list);
            return results;
        }
        for (int i = 0; i < nums.length; i++) {
            list.add(nums[i]);
            dfs(nums, list);
            list.remove(list.size() - 1);
        }
        return results;
    }

    private void dfs(int[] nums, List<Integer> list) {
        if (list.size() == nums.length) {
            results.add(new ArrayList<>(list));
            return;
        }
        for (int j = 0; j < nums.length; j++) {
            if (list.contains(nums[j])) {
                continue;
            }
            list.add(nums[j]);
            dfs(nums, list);
            list.remove(list.size() - 1);
        }
    }

}
```