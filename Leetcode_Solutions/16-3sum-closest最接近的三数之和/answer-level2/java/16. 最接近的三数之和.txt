/**
 * Project:
 * Author : zhaozhen
 * Email  :
 * Date   : 2019/10/17
 *
 * 解题思路: 固定一个数值 右端进行双指针
 *
 */
```
public int threeSumClosest(int[] nums, int target) {
    Arrays.sort(nums);
    int l = 1;
    int r = nums.length-1;
    int btw = Integer.MAX_VALUE;
    int sum_res = 0;
    for(int i = 0;i < nums.length;i++){
        l = i+1;
        r = nums.length-1;
        while(l < r){
            int sum_cur = nums[i] + nums[l] + nums[r];
            if(Math.abs(sum_cur - target) < btw){
                btw = Math.abs(sum_cur - target);
                sum_res = nums[i] + nums[l] + nums[r];
            }
            if(sum_cur == target){
                return sum_cur;
            }else if(sum_cur > target){
                r--;
            }else {
                l++;
            }

        }
    }
    return sum_res;

}

```