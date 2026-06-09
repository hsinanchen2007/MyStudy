### 解题思路
1. 数组排序
2. 每找到一个子集，就在该子集的基础上增添元素变长子集(进行下一次递归)
3. 回溯之前要对元素判重，如果元素重复就不要进行迭代

### 代码

```java
class Solution {
    private void backtrack(int []nums, int start, List<Integer> tmp,List<List<Integer>> res) {
        for (int i=start; i < nums.length; i++) {
            tmp.add(nums[i]);
            res.add(new ArrayList<>(tmp));
            backtrack(nums, i+1, tmp, res);
            for (;i < nums.length-1 && nums[i] == nums[i+1];i++);
            tmp.remove(tmp.size()-1);
        }
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        res.add(new ArrayList<>());
        backtrack(nums, 0, new ArrayList<>(), res);
        return res;
    }
}
```