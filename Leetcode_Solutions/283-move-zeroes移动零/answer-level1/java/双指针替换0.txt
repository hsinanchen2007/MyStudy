定义两个指针i,j，然后遍历数组，i跟j同时往前走，当遇到0时j停下，i继续往前走。当nums[i]不为0时则将num[i]的元素赋给j的位置，j++,nums[i]被赋值为0
```
public void moveZeroes(int[] nums) {
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                if(i!=j) {
                    nums[j] = nums[i];
                    nums[i] = 0;
                }
                j++;
            }
        }
    }
```
在i等于j的情况下，如果num[i]不为0，将num[i]的元素赋给j的位置其实就是自己赋值给自己，所以可以加一个判断条件，i不等j的时候才替换0