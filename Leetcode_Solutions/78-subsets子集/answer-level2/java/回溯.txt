### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        boolean[] visited = new boolean[nums.length];
        ArrayList<List<Integer>> res = new ArrayList<>();
        ArrayList<Integer> tmp = new ArrayList<>(); 
        backtrack(res, tmp, nums, visited, 0);
        return res;
    }
    public void backtrack(List<List<Integer>> res, List<Integer> tmp, int[] nums, boolean[] visited, int m){
        res.add(new ArrayList(tmp));
        for(int i = m; i < nums.length; i++){
            if(visited[i]) continue;
            tmp.add(nums[i]);
            visited[i] = true;
            backtrack(res, tmp, nums, visited, i+1);
            tmp.remove(tmp.size()-1);
            visited[i] = false;
        }
    }
}
```