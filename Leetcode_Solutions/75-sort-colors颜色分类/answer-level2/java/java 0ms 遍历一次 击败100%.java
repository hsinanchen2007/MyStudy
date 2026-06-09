
```java
class Solution {
    public void sortColors(int[] nums) {
        int red = 0;
        int white = 1;
        int blue = 2;
        int length = nums.length;
        int redPtr = 0;
        int bluePtr = length - 1;
        for(int i  = 0; i <= bluePtr; i ++){
            if(nums[i] == red){
                exch(i, redPtr++, nums);
            }
            else if(nums[i] == blue){
                while(bluePtr > 0 && nums[bluePtr] == blue) bluePtr--; // 去掉所有已经是2的情况
                if(i >= bluePtr) return;                               // i以后都为2，不需要再排序
                exch(i, bluePtr--, nums);
                if(nums[i] == red) exch(i, redPtr++, nums);            // 交换后i为0，再交换一次
            }
            else{
                continue;
            }
        }
    }
    private void exch(int i, int j, int[]nums){
        if(i == j) return;
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```

用两个指针分别表示当前红色（0）交换到的位置、蓝色（2）交换到的位置。
设为redPtr、bluePtr
redPtr表示i < redPtr所有元素都为0，bluePtr表示i > bluePtr所有元素都为2

当前元素设为i有三种情况：（以下交换代表交换指针所在位置元素）
1. 红色，则交换i、redPtr
2. 蓝色，则交换i、bluePtr。注意此时交换后i分为两种情况：i是红色、i是白色（1）
3. 承接2，如果i是红色，需要再将i和redPtr交换
4. 白色，不做交换。
