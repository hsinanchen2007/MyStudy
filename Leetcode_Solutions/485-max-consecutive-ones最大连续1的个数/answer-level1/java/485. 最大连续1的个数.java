/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/18
 *
 * 解题思路1: 使用一个锁 in 判断是否当前正在连续1的阶段内 其余分三个情况判断
 *
 * 解题思路2: 双指针也可以解决 一前一后 区间是连续的1
 *
 */

```

 public int findMaxConsecutiveOnes(int[] nums) {

    int max = 0;
    int current = 0;
    boolean in = false;

    for(int i = 0;i < nums.length;i++){

        //到达末尾
        if(nums[i] == 0 && in == true){
            in = false;
            if(max < current){
                max = current;
            }
            current = 0;
        }

        //中间
        if(nums[i] == 1 && in == true){
            current ++;
        }

        //开始
        if(nums[i] == 1 && in == false){
            in = true;
            current ++;
        }
    }

    if(max < current) max = current;
    return max;
}

```