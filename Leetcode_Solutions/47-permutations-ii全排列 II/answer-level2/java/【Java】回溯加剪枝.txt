![image.png](https://pic.leetcode-cn.com/e210ad50957d5473f64668a0c28d3c23506a1894c2dd6d8904c38cf4f2176a54-image.png)
```java
    List<List<Integer>> ans = new ArrayList<>();
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<Integer> path = new ArrayList<>();
        int[] visist = new int[nums.length];
        Arrays.sort(nums);
        dfs(path, nums, 0, visist);
        return ans;
    }

    public void dfs(List<Integer> path, int[] nums, int u, int[] visit) {
        if (u == nums.length) {
            ans.add(new ArrayList<>(path));
            return;
        }
        for (int i = 0; i < nums.length; i ++) {
            if (visit[i] == 1) {
                continue;
            }
            // 去重：和第i-1个数相等且第i-1个数已被计算
            if (i > 0 && nums[i] == nums[i -1] && visit[i-1] ==1) {
                continue;
            }
            visit[i] = 1;
            path.add(nums[i]);
            dfs(path, nums, u + 1, visit);
            path.remove(path.size() - 1);
            visit[i] = 0;
        }
    }
```
