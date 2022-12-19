/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/28
 *
 * 解题思路: 因为数组的值在一定的范围内 因此可以自定义hash数组(整数)
 *
 */
```
public int[] findErrorNums(int[] nums) {

    int res[] = new int[2];

    int count[] = new int[10001];
    for(int i = 0; i < nums.length; i++){
        count[nums[i]]++;

    }

    for(int i = 1; i <= nums.length; i++){
        if(count[i] == 2)
            res[0] = i;
        if(count[i] == 0)
            res[1] = i;
    }

    return res;

}
```