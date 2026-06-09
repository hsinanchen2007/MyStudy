## 解题思路
题目有两个关键点：

1. 排序：采用快速排序的方法
2. 比较：比较两个数字拼接在一起后的值

## 解题方式
```
public String largestNumber(int[] nums) {
        nums = sort(nums, 0, nums.length - 1);

        if (nums[0] == 0) {
            return "0";
        }

        String result = "";
        for (int i : nums) {
            result = result + i;
        }

        return result;
    }

    public int[] sort(int[] nums, int start, int end) {

        int op = nums[(start + end) / 2];
        int i = start;
        int j = end;
        while (i < j) {
            while (i < j && compare(nums[j], op) < 0) {
                j--;
            }

            while (i < j && compare(op, nums[i]) < 0) {
                i++;
            }

            if (i < j && compare(nums[i], nums[j]) == 0) {
                i++;
            } else {

                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        if (i - 1 > start) {
            nums = sort(nums, start, i - 1);
        }

        if (j + 1 < end) {
            nums = sort(nums, j + 1, end);
        }

        return nums;
    }

    public int compare(int a, int b) {

        return (a + "" + b).compareTo(b + "" + a);
    }
```

