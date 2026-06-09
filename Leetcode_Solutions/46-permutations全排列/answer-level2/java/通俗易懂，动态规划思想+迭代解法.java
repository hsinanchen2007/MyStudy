```
    /**
     * 1. 定义动态规划求解问题dp[n]，表示前i个数字组合的结果
     * 2. 状态转移方程dp[n]，考虑dp[n-1]的解已经知道了，那么第n个字母
     * 可以出现在任意两个字母的中间或者说是最左和最右边，有n种情况
     * 如 nums= {1, 2, 3}，n = 3时
     * n-1=2时有两种情况，{1, 2} {2, 1}
     * 以 {1, 2} 为例 数字3有3个位置可以插入
     * {3,1,2} {1,3,2} {1,2,3}
     * 3. 边界条件dp[1] = Arrays.asList(nums[0])
     */
    public List<List<Integer>> permute(int[] nums) {
        int len = nums.length;
        if (len == 0) {
            return new ArrayList<>();
        }
        List<Integer> first = new ArrayList<>(Arrays.asList(nums[0]));
        List<List<Integer>> iter = new ArrayList<>(Arrays.asList(first));

        if (len == 1) {
            return iter;
        }

        for (int i=1; i<len; i++) {
            iter = calcIteration(iter, nums[i]);
        }

        return iter;
    }

    /**
     * 通过前n-1个字母的解，求出前n个字母的解
     */
    private List<List<Integer>> calcIteration(List<List<Integer>> iter, int item) {
        List<List<Integer>> result = new ArrayList<>();
        for (List<Integer> list : iter) {
            int localLen = list.size();
            for (int i=0; i<=localLen; i++) {
                List<Integer> tmp = new ArrayList<>(list);
                tmp.add(i, item);
                result.add(tmp);
            }
        }

        return result;
    }
```

