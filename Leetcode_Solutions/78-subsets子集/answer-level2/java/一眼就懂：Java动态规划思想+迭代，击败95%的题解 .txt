    /**
     * 1. 定义动态规划问题 dp[i] 表示前i个数字的非空子集
     * 2. 状态转移方程 dp[i]的子集等于
     * （1）dp[i-1]的子集
     *  (2) dp[i-1]的子集序列 + nums[i]结尾
     *  (3) 只包含 nums[i]的集合 { nums[i] }
     */
    public List<List<Integer>> subsets(int[] nums) {
        int len = nums.length;
        if (len == 0) {
            return new ArrayList<>();
        }

        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < len; i++) {
            // part 1: dp[i-1]的子集
            List<List<Integer>> localList = new ArrayList<>(result);
            // part 2: dp[i-1]的子集序列 + nums[i]结尾
            for (List<Integer> oneSet : result) {
                List<Integer> tmp = new ArrayList<>(oneSet);
                tmp.add(nums[i]);
                localList.add(tmp);
            }
            // part 3: 只包含 nums[i]的集合 { nums[i] }
            List<Integer> oneItemList = new ArrayList<>(Arrays.asList(nums[i]));
            localList.add(oneItemList);
            result = localList;
        }
        
        // 特殊空集
        result.add(new ArrayList<>());
        return result;
    }