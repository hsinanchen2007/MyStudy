### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {
        int len = nums.length;
        List<List<Integer>> paths = new ArrayList<>();
        if(len == 0) {
            return paths;
        }
        List<Integer> path = new ArrayList<>();
        Set<List<Integer>> set = new HashSet<>();
        dfs(nums, 0, paths, path, set, Integer.MIN_VALUE);
        return paths;
    }

    private void dfs(int[] nums, int loc, List<List<Integer>> paths, List<Integer> path, Set<List<Integer>> set, int preNum) {
        if(path.size() >= 2) {
            if(!set.contains(new ArrayList<>(path))) {
                paths.add(new ArrayList<>(path));
                set.add(new ArrayList<>(path));
            }
            if(loc >= nums.length) {
                return;
            }
        }
        for(int i = loc; i < nums.length; i++) {
            if(nums[i] >= preNum) {
                path.add(nums[i]);
                dfs(nums, i + 1, paths, path, set, nums[i]);
                path.remove(path.size() - 1);
            }
        }
    }
}
```