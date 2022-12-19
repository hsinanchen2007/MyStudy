### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<List<Integer>> res = new LinkedList<>();



    /* 主函数，输入一组不重复的数字，返回它们的全排列 */
    List<List<Integer>> permute(int[] nums) {
        // 记录「路径」
        LinkedList<Integer> track = new LinkedList<>();
        backtrack(nums, track);
        return res;
    }

    // 路径：记录在 track 中
    // 选择列表：nums 中不存在于 track 的那些元素
    // 结束条件：nums 中的元素全都在 track 中出现
    void backtrack(int[] nums, LinkedList<Integer> track) {
        // 触发结束条件
        if (track.size() == nums.length) {
            res.add(new LinkedList(track));
            return;
        }

        for (int i = 0; i < nums.length; i++) { // 这里的循环本来应该是 for(num : selectList)来着，但是selectList作为LinkedList不能再循环中删除
            // 排除不合法的选择（选择列表  和  路径  是互补的，相加起来是一个数组nums，所以可以通过track来当选择列表来用）
            // 
            if (track.contains(nums[i]))
                continue;
            // 做选择
            track.add(nums[i]);
            // 进入下一层决策树
            backtrack(nums, track);
            // 取消选择
            track.removeLast();
        }
    }
}
```