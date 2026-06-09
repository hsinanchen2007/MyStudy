更多双指针相关的算法题[参考此文](https://blog.csdn.net/reed1991/article/details/55096982)
```
public int threeSumClosest(int[] nums, int target) {
        assert nums.length > 2;
        Arrays.sort(nums);
        int left;
        int right;
        int sum3;  //数组中的三个数的和
        int res = 0;  //记录返回结果
        int tmp = Integer.MAX_VALUE; //记录sum3和target的差的绝对值
        for (int i = 0; i < nums.length - 2; i++) {
            left = i + 1;
            right = nums.length - 1;
            while (left < right) {
                sum3 = nums[left] + nums[right] + nums[i];
                //如果已经找到等于target的三个数，直接返回即可。
                if(sum3 == target){
                    return target;
                }
                if (Math.abs(sum3 - target) < tmp) {
                    tmp = Math.abs(sum3 - target);
                    res = sum3;
                }
                if (sum3 > target) {
                    right--;
                } else {
                    left++;
                }
            }

        }

        return res;
    }
```
