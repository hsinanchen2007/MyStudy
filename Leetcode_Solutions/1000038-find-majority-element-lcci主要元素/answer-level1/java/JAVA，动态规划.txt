```
package leetCodeTest;

import java.util.Arrays;

public class 主要元素 {
    public static void main(String[] args) {
        int[] nums = new int[]{1,2,5,9,5,9,5,5,5};
        int i = majorityElement(nums);
        System.out.println("i = " + i);
    }

    /**
     *
     * 首先对原数组排序让相同元素都处于紧凑状态。
     * 使用sum数组存储每一个元素从下标0-i（i为当前遍历数组的下标）之间出现的次数。
     * 在存储sum数组的同时，将sum数组中的最大值count取出，并记录当sum为最大的时候的下标flag，
     * 最后判断当前count是否大于nums数组的一半，如果大于nums数组的一半，
     * 就返回nums中下标为flag的值，否则返回-1.
     * @param nums
     * @return
     */
    public static int majorityElement(int[] nums) {
        if (nums.length == 0)
            return -1;
        if (nums.length == 1)
            return nums[0];
        Arrays.sort(nums);//对原数组进行排序
        int i,temp = Integer.MAX_VALUE,count = Integer.MIN_VALUE,flag = 0;
        int[] sum = new int[nums.length];//总和数组
        for (i=0;i<nums.length;i++){
            //使用temp判断当前元素与上一个元素是否相同，如果不同就重新计数
            if (temp != nums[i]){
                sum[i] = 1;
                temp = nums[i];
            }else {
                sum[i] = sum[i-1] + 1;
            }
            //如果当前的sum值大于count就替换count，并记录下标到flag
            if (sum[i] > count){
                count = sum[i];
                flag = i;
            }
        }
        //如果count大于nums数组的一半就返回nums[flag]
        return count>nums.length/2 ? nums[flag]:-1;
    }
}

```
