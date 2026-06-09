
/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/9
 *
 * 解题思路: 数组记录当前数字右侧(左侧)的数字之和  1.使用两个数组进行记录左侧右侧数字总和 2.只记录右侧 左侧的总和在线性遍历判定的时候一起做
 *
 */
```

public int pivotIndex(int[] nums) {
    int[] left = new int[nums.length];
    int[] right = new int[nums.length];

    int sum = 0;
    for(int i = 0;i < nums.length;i++){
        sum += nums[i];
        left[i] = sum;
    }
    sum = 0;
    for(int i = nums.length - 1;i >= 0;i--){
        sum += nums[i];
        right[i] = sum;
    }

    for(int i = 0;i < nums.length;i++){
        if(left[i]  == right[i]){
            return i;
        }
    }
    return -1;
}

public int pivotIndex2(int[] nums) {
    int[] right = new int[nums.length];

    int sum = 0;

    for(int i = nums.length - 1;i >= 0;i--){
        sum += nums[i];
        right[i] = sum;
    }

    sum = 0;
    for(int i = 0;i < nums.length;i++){
        sum += nums[i];
        if(sum  == right[i]){
            return i;
        }
    }
    return -1;
}


```