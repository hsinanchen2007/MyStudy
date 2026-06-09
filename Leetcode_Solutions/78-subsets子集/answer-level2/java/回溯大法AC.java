### 解题思路
见代码

### 代码

```java
class Solution {
    List<List<Integer>> result = new LinkedList<>();
    public List<List<Integer>> subsets(int[] nums) {
        LinkedList<Integer> track = new LinkedList<>();
        backtrack(nums, 0, track);
        return result;
    }

    // nums选择列表
    // 路径记录在track
    void backtrack(int[] nums, int start, LinkedList<Integer> track) {
        result.add(new LinkedList<>(track));
        for (int i = start; i < nums.length; i++) {
            // 选择
            track.add(nums[i]);
            // 回溯
            backtrack(nums, i + 1,  track);
            // 撤销
            track.removeLast();
        }
    }
}
```