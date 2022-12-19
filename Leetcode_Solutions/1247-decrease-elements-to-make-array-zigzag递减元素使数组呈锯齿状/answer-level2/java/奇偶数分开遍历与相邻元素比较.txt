执行用时 : 0 ms, 在所有 java 提交中击败了100.00% 的用户


```java
package com.skjilygao.test;

/**
 * 给你一个整数数组 nums，每次 操作 会从中选择一个元素并 将该元素的值减少 1。
 * <b> 如果符合下列情况之一，则数组 A 就是 锯齿数组：
 * <b> 每个偶数索引对应的元素都大于相邻的元素，即 A[0] > A[1] < A[2] > A[3] < A[4] > ...
 * <b> 或者，每个奇数索引对应的元素都大于相邻的元素，即 A[0] < A[1] > A[2] < A[3] > A[4] < ...
 * <b> 返回将数组 nums 转换为锯齿数组所需的最小操作次数。
 * <b> 参考：https://leetcode-cn.com/problems/decrease-elements-to-make-array-zigzag
 * @author skyjilygao
 * @since 20191125
 */
class ArrayZigzag {
    public int movesToMakeZigzag(int[] nums) {
        // 偶大相邻
        int opt = evenNums(copyNums(nums));
        // 为0，就表示已经是锯齿数组
        if(opt == 0){
            return 0;
        }

        int oddOpt = oddNums(nums);
        opt = opt < oddOpt ? opt : oddOpt;
        return opt;
    }

    /**
     * 赋值数组
     * @param nums
     * @return
     */
    private int[] copyNums(int[] nums){
        int len = nums.length;
        int[] nums1 = new int[len];
        for(int i = 0; i < len; i++){
            nums1[i] = nums[i];
        }
        return nums1;
    }
    /**
    * 奇数索引大于相邻
    */
    private int oddNums(int[] nums){
        return getOpts(nums, 1, 0);
    }
    /**
    * 偶数索引大于相邻
    */
    private int evenNums(int[] nums){
        return getOpts(nums, 0, 0);
    }
    
    /**
    * 跟相邻的元素比较
    */
    private int getOpts(int[] nums, int startIndex, int tmpOpt){
        int len = nums.length;
        for(int i = startIndex; i < len; i+=2){
            if(i-1 >= 0 && nums[i] <= nums[i-1]){
                int curtOpt = nums[i-1] - nums[i] + 1;
                tmpOpt += curtOpt;
                nums[i-1] -= curtOpt;
            }
            if(i+1 < len && nums[i] <= nums[i+1]){
                int curtOpt = nums[i+1] - nums[i] + 1;
                tmpOpt += curtOpt;
                nums[i+1] -= curtOpt;
            }
           
        }
        return tmpOpt;
    }
    
}
```
