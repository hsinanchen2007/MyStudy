/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/10
 *
 *解题思路: 找出最大值和次大值进行比较即可  关键问题:题目中 是否至少是数组中每个其他数字(与当前最大值不相同的数字)的两倍
 *
 * 如果只有一个数字 返回0 因为他比其他数字都大
 *
 */
```
 public int dominantIndex(int[] nums) {
    int max = -1;
    int max_index = -1;
    int max_2 = -1;
    for(int i = 0;i < nums.length;i++){
        if(nums[i] > max){
            max_2 = max;
            max = nums[i];
            max_index = i;
        }else if(nums[i] > max_2 && nums[i] != max){
            max_2 = nums[i];
        }
    }

    //只有一个数字 max > -1*2 返回0
    if(max >= max_2*2){
        return max_index;
    }else {
        return -1;
    }
}
```