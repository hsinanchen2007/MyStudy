/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/28
 *
 * 解题思路: 贪心法比较
 *
 */
```
public int findLengthOfLCIS(int[] nums) {
    if(nums.length == 1 || nums.length == 0){
        return nums.length;
    }
    int max_LCIS = 1;
    int cur_LCIS = 1;
    for(int i = 0;i < nums.length - 1;i++){
        if(nums[i] < nums[i+1]){
            cur_LCIS++;
        }else{
            if(cur_LCIS > max_LCIS){
                max_LCIS = cur_LCIS;
            }
            cur_LCIS = 1;
        }
    }
    if(max_LCIS < cur_LCIS){
        max_LCIS = cur_LCIS;
    }
    return max_LCIS;
}
```