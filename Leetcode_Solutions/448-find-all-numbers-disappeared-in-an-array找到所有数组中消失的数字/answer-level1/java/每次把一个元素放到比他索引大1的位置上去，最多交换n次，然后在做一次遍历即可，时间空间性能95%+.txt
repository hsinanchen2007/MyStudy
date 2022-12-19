public static List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> notAppearing = new ArrayList<>();
        int n = nums.length;

        //每一轮都可以把一个数字放到自己的位置上去 最后比较一下索引和其值的差是否为1
        int j = 0;
        int temp;
        int count = 0;//退出循环的计数器
        while (j < n) {
            while ((nums[j] - j) != 1 &&
                    ((nums[nums[j] - 1] - (nums[j] - 1)) != 1)) { //当元素不在她应该在的位置 需要做交换
                temp = nums[j];
                nums[j] = nums[temp - 1];
                nums[temp - 1] = temp;
                count++;
            }
            j++;
        }
        for (int i = 0; i < n; i++) {
            if ((nums[i] - i) != 1) {
                notAppearing.add(i + 1);
            }
        }
        return notAppearing;
    }
//每次把一个元素放到比他索引大1的位置上去，最多交换n次，时间复杂度为o(n)