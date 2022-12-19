/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/2
 *
 * 解题思路: 0~100中缺一个数，怎么找出来 求出1~100的和再减去当前序列的和 (0+100)/2*(100+1)-sum([0,1,....100])
 * 解题思路2: 异或运算 1^2^3^1^2 = 3;  相同返回0 0异或任何一个数都等于这个数
 */
```
public int missingNumber(int[] nums) {
    int n = nums.length;
    int sum = 0;
    for(int i = 0;i < nums.length;i++){
        sum += nums[i];
    }
    int res = (0+n)*(n+1)/2 - sum;
    return res;
}



```