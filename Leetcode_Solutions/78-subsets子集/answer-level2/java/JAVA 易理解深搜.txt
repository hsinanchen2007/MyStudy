执行用时 :1 ms, 在所有 java 提交中击败了99.28%的用户
内存消耗 :36 MB, 在所有 java 提交中击败了70.40%的用户

看错题目了，以为不能是有重复子集（比如【1，1,2,3】，不能出现两次1,2,3）,简单写了下代码后想提交下，看看什么问题然后再进一步debug，但是通过了，给我惊讶的。后来才发现，题目说的是不能有重复数。
给大家分享下，通过代码吧，这边我补充了些注释方便理解。

```
public class Subsets {

    private List<List<Integer>> ans = new ArrayList<>();
    private Stack<Integer> path = new Stack<>();
    private int n;

    public List<List<Integer>> subsets(int[] nums) {
        n = nums.length;

        dfs(0, nums);

        return ans;

    }

    /**
     * @param p    当前位置
     * @param nums
     */
    public void dfs(int p, int[] nums) {
        // 如果当前位置到末尾了，说明所有位置都已经做过抉择了。
        if (p == n) {

            // 将当前路径（所有抉择的结果)添加到答案中
            ans.add(new ArrayList<>(path));
            return;
        }

        // 1. 选当前位置上的数字
        path.push(nums[p]);

        // 处理下一个位置
        dfs(p + 1, nums);

        // 回溯，返回状态
        path.pop();

        // 处理下一个位置（不选当前位置上的数字)
        dfs(p + 1, nums);
    }
}

```
