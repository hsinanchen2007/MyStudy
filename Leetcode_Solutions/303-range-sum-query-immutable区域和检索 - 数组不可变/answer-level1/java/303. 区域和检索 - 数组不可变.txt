/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/3
 * 
 * 解题思路1: 暴力法
 * 
 * 解题思路2: 使用数组存储当前0~0 0~1 0~2 0~3 .... 0~n 的和sum，求取num[i.+.j] == sum[j] - sum[i -1]
 * 
 * 解题思路3: 将上述存储放在hash中
 */
```
public leetcode303(int[] nums) {
    sum = new int[nums.length];

    //缓存
    int t = 0;
    for(int i = 0;i < nums.length;i++){
        t += nums[i];
        sum[i] = t;
    }
}

public int sumRange(int i, int j) {
    if(i == 0){
        return sum[j];

    }else {
        return sum[j] - sum[i - 1];
    }
}
```