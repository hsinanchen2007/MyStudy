**1.此方法采用的是指针跳过多余重复元素的方法;
2.遍历数组，当有两个连续的数字重复的时候就要进行判断，先保存当前val，然后再复制两个重复的元素，接着指针i开始跳过多余的重复元素即可;
3.完结。**

        public int removeDuplicates(int[] nums) {
            int m = 0;
            for (int i = 0; i < nums.length;) {
                if (i < nums.length - 1 && nums[i] == nums[i + 1]) {
                    int val = nums[i];
                    nums[m++] = nums[i++];
                    nums[m++] = nums[i++];
                    while (i < nums.length && nums[i] == val)
                        i++;
                } else
                    nums[m++] = nums[i++];
            }
            return m;
        }