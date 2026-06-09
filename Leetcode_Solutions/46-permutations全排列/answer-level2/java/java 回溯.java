### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * 排列问题，第一想法：回溯
 */
class Solution {
    List<List<Integer>> resList;

    public List<List<Integer>> permute(int[] nums) {
        resList = new ArrayList<>();
        //list 需要自己恢复状态

        //visited?
        boolean[] visited = new boolean[nums.length];
        for (int i = 0; i < nums.length; i++) {
            visited[i] = false;
        }

        backtrack(nums, visited, new ArrayList<>());
        return resList;

    }

    public void backtrack(int[] nums, boolean[] visited, ArrayList<Integer> res) {
        if (res.size() == nums.length) {
            resList.add(new ArrayList<>(res));
        }
        for (int i = 0; i < nums.length; i++) {
            if (!visited[i]) {
                res.add(nums[i]);
                visited[i] = true;
                backtrack(nums, visited, res);
                //恢复
                visited[i] = false;
                res.remove(res.size() - 1);
            }
        }
    }
}
```