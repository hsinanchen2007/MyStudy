执行用时 :1 ms, 在所有 Java 提交中击败了99.76%的用户
内存消耗 :35.4 MB, 在所有 Java 提交中击败了85.53%的用户

根据抽屉原理：数组的长度n，则答案最大只能是n+1；
可以使用hash函数将答案空间映射到长度为n+1的数组上，再遍历数组找到最小的没出现的正整数。
为实现常数空间复杂度，可以使用原数组的空间：
如果 0<nums[i]<=nums.length;
则将nums[i] 跟 nums[nums[i]-1]交换;
最后再遍历数组，如果num[i] != i+1,则i+1就是缺失的最小正整数。

```
    public int firstMissingPositive(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            while(nums[i] != i+1 && nums[i] > 0 && nums[i] <= nums.length && nums[i] != nums[nums[i]-1]){
                int j = nums[i];
                nums[i] = nums[j-1];
                nums[j-1] = j;
            }
        }

        for (int i = 0; i < nums.length; i++) {
            if(nums[i] != i+1){
                return i+1;
            }
        }

        return nums.length+1;
    }
```


