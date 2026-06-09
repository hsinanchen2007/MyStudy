
    /**
     * 1121. 将数组分成几个递增序列
     * 给你一个 非递减 的正整数数组 nums 和整数 K，判断该数组是否可以被分成一个或几个 长度至少 为 K 的 不相交的递增子序列
     * 输入：nums = [1,2,2,3,3,4,4], K = 3
     * 输出：true
     * 解释：
     * 该数组可以分成两个子序列 [1,2,3,4] 和 [2,3,4]，每个子序列的长度都至少是 3。
     *
     * 说明：
     * 这个题关键在于对题目的理解， 如果数组中有相同的数字，那么代表相同数字必须要被分割到不同的数组中，因此有几个相同数字，就有几个数组；
     * 因此可以简单的判断
     *
     * */
    public boolean test_1121(int[] nums, int k){
        int len = nums.length;
        //异常数据的检查处理；
        if(nums == null || nums.length ==0||k<= 0 || len <k) return Boolean.FALSE;

        //通过Map统计每个数字出现的次数，并找出出现最多的次数；
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        Integer num;
        Integer value;
        int maxLen =0;
        for (int i = 0; i < nums.length; i++) {
            num = nums[i];
            if(map.containsKey(num)) {
                value = map.get(num) +1;
            }else{
                value =1;
            }
            map.put(num,value);
            if(value>maxLen) maxLen = value;
        }
        return  len<(k*maxLen) ? Boolean.FALSE:Boolean.TRUE;
    }