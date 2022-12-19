### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<List<Integer>> ret = new ArrayList<>();
    public List<List<Integer>> subsets(int[] nums) {
        List<Integer> already = new ArrayList<>();
        backtracking(already, nums, 0);
        return ret;
    }
    private void backtracking(List<Integer> already, int[] nums, int start){
        ret.add(new ArrayList<>(already));
        for(int i = start; i < nums.length; i++){
            already.add(nums[i]);
            backtracking(already, nums, i+1);
            already.remove(already.size() - 1);
        }
        return;
    }
}
```