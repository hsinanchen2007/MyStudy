```
/**
 * 连续子数组，第一反应就是滑动窗口，考虑到求的是乘积，当窗口内存在0时，窗口怎么移动都没用，所以可以根据0将数组分成多个子数组。
 * 那么现在子数组就存在两种可能，1.都是正数，那么直接将数组所有数相乘既可得出结果。2.存在负数，那么有两种可能，偶数个负数，跟1一样。
 * 奇数个负数，那么根据某个负数分割数组，即可得到两个正数结果的值，且该负数必然处于数组中的第一个或最后一个（可以证明这样得出的乘积最大）。
 * 利用滑动窗口，当num不等于0时，右边界移动，当num等于0时，判断窗口所有值的乘积，大于0则跳过，小于0则将左边界移动，直到乘积大于0（第一个负数分割点）。
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxProduct(int* nums, int numsSize){
	int i, j, sum, max;
	i = 0; sum = 1; max = INT_MIN;
	for(j = 0; j <= numsSize; j++){
	    if(j == numsSize || nums[j] == 0){
		max = MAX(max, j < numsSize ? 0 : max);
		while(sum < 0 && i < j - 1){
		    sum /= nums[i++];
                    max = MAX(max, sum);
	        }
                sum = 1;
		i = j + 1;
	    }else{
		sum *= nums[j];
		max = MAX(max, sum);
	    }
	}
	
	return max;
}
```
