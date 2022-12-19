class Solution {
    public int dominantIndex(int[] nums) {
        int size = nums.length;
        if (nums == null || size == 1) {
            return 0;
        }

        int maxNumber = 0;
        int secondMaxNumber = 0;
        int index = 0;
        
        // 初始时将 maxNumber 设置为 num[0] num[1] 中相比较大的那个数, secondMaxNumber 为较小的那个数
        // index 为索引位置
        if (nums[0] > nums[1]) {
            maxNumber = nums[0];
            secondMaxNumber = nums[1];
            index = 0;
        } else {
            maxNumber = nums[1];
            secondMaxNumber = nums[0];
            index = 1;
        }

        // 从index = 2 开始遍历, 
        // 1). 如果 num[i]大于之前的 maxNumber,  重新赋值: secondMaxNumber = maxNumber;  nums[i] = maxNumber;         //     index 等于现在最大数的索引   
        // 2). 如果 num[i] 比 secondMaxNumber 大但小于 maxNumber, secondMaxNumber 重新赋值
        // 3). 其余情况不做处理;
        for (int i = 2 ; i < size ; i ++) {
            if (nums[i] > maxNumber) {
                secondMaxNumber = maxNumber;
                maxNumber = nums[i];
                index = i;
            } else if (nums[i] < maxNumber && nums[i] > secondMaxNumber) {
                secondMaxNumber = nums[i];
            }
        }

        // 乘以2 比较
        if (secondMaxNumber * 2 <= maxNumber) {
            return index;
        }
        return -1;
    }
}