执行用时 : 3 ms, 在Maximum Product Subarray的Java提交中击败了89.39% 的用户
内存消耗 : 35.3 MB, 在Maximum Product Subarray的Java提交中击败了84.74% 的用户

经验不足，代码里if判断那里写的总感觉有点蹩脚，欢迎各路大神帮忙修改优化，写出优雅的代码！

    public int maxProduct(int[] nums) {
        if (nums == null || nums.length == 0) return 0;//参数有效性

        int max = nums[nums.length - 1];//节点状态最大值 这里不用数组，只需要保存上一个节点的最大值和最小值
        int min = nums[nums.length - 1];//节点状态最小值
        int result = nums[nums.length - 1];//最大节点值

        for (int i = nums.length - 2; i >= 0; i--) {//直接从倒数第2个元素开始向前遍历
            if (nums[i] < 0) {//判断当前元素正负 因为负数计算最大值要乘以上一个节点的最小值才行
                int temp = max;
                max = nums[i] > nums[i] * min ? nums[i] : nums[i] * min;
                min = nums[i] < nums[i] * temp ? nums[i] : nums[i] * temp;
            }else {
                max = nums[i] > nums[i] * max ? nums[i] : nums[i] * max;
                min = nums[i] < nums[i] * min ? nums[i] : nums[i] * min;
            }
            if (result < max) result = max;//记录目前为止的最大值
        }
        return result;
    }