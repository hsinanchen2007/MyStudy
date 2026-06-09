### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();
        if(nums == null){
            return results;
        }
        if(nums.length == 0){
            results.add(new ArrayList<>());
            return results;
        }

        Arrays.sort(nums);
        dfs(nums, new boolean[nums.length], new ArrayList<>(), results);

        return results;
    }

    private void dfs(int[] nums, boolean[] visited, List<Integer> subsets, List<List<Integer>> results) {
        if(subsets.size() == nums.length){
            results.add(new ArrayList<>(subsets));
        }

        for (int i = 0; i < nums.length; i++) {
            if(visited[i]){
                continue;
            }
            //跳过会造成重复的情况
            if(i > 0 && nums[i] == nums[i - 1] && visited[i - 1]){
                continue;
            }
            subsets.add(nums[i]);
            visited[i] = true;
            dfs(nums, visited, subsets, results);
            visited[i] = false;
            subsets.remove(subsets.size() - 1);
        }
    }
}
```