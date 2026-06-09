其实思路很简单，贪心算法
每一步最优的条件就是：下一步选择的跳跃点的数字和选择的跳跃点距离当前点的差值，两者之和最大即可
，其他注意一些判空、循环判断即可

public int jump(int[] nums) {
        if (nums.length <= 1) {
            return 0;
        }
        int i = 0;
        int minTimes = 1;
        while (i < nums.length-1) {
            int nowInt = nums[i];
            if (nowInt > 0 && nowInt < nums.length-1-i) {
                int maxNext = nums[i+1]+1;
                int maxIndex = i+1;
                for (int j = 2; j <= nowInt; j++) {
                    if ((i+j) <= nums.length-1) {
                        if ((nums[i+j]+j)>=maxNext) {
                            maxNext = nums[i+j]+j;
                            maxIndex = i+j;
                        }
                    }else {
                        return minTimes;
                    }

                }
                i = maxIndex;
                minTimes += 1;
            }else {
                return minTimes;
            }

        }
        return minTimes;
    }