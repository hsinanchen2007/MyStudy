int findUnsortedSubarray(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = 0;
        //正常的情况是从左往右递增，从右往左递减
        //1.先通过两个for循环找出左右两边不合理的值（即从左往右出现值减少，从右往左出现值增加）
        for (int i = 0; i < size - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                left = i;
                break;
            }
        }
        for (int i = size - 1; i > 0; i--)
        {
            if (nums[i] < nums[i - 1])
            {
                right = i;
                break;
            }
        }
        //2.最终结果一定包含以上的[left,right];但有可能出现[left,right]的值过小或过大，因此需要找出区间内的最小以及最大值。
        int min = INT_MAX, max = INT_MIN;
        for (int i = left; i <= right; i++)
        {
            int a = nums[i];
            if (a < min)
                min = a;
            if (a > max)
                max = a;
        }
        for (int i = left; i >= 0; i--)
        {
            if (nums[i] <= min)
                break;
            else
                left = i;
        }
        //找出区间内的最小与最大值之后，需要将区间像左右两边扩充，比如如下的序列
        //{0,3,4,2,1,7,6,5,8},第一步是找到2，5，第二步是找到2,5之间的最小最大值：1和7，第三步是向外扩充区间
        for (int i = right; i < size; i++)
        {
            if (nums[i] >= max)
                break;
            else
                right = i;
        }
        return ((right != left) ? (right - left + 1) : 0);
    }