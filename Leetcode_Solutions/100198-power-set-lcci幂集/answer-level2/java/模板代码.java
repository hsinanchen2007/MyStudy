### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();
        
        dfs(nums, 0, new ArrayList<>(), results);
        return results;
    }
    
    private void dfs(int[] nums, int index, List<Integer> subsets, List<List<Integer>> results) {
        results.add(new ArrayList(subsets));
        
        for(int i = index; i < nums.length; i++){
            subsets.add(nums[i]);
            dfs(nums, i + 1, subsets, results);
            subsets.remove(subsets.size() - 1);
        }
    }
}
```