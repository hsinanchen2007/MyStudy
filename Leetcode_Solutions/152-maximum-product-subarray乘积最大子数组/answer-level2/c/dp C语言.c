### 解题思路
动态规划，状态转移方程直接比较当前值，最大值和当前值乘积以及最小值和当前值乘积谁大谁小

### 代码

```c
#define GETMAX(a,b,c) (a)>(b) ? ( (a)>(c)? (a) : (c)) : ( (b)>(c) ? (b) :(c) )
#define GETMIN(a,b,c) (a)<(b) ? ( (a)<(c)? (a) : (c)) : ( (b)<(c) ? (b) :(c) )
int maxProduct(int* nums, int numsSize){
	int *max = (int*) malloc (sizeof(int)*numsSize);
	int *min = (int*) malloc (sizeof(int)*numsSize) ;
	int result;
	for(int i=0;i<numsSize;i+=1){
		if(0==i){
			result = max[i] = min[i] = nums[i];
		}
		else if(0<i){
			max[i] = GETMAX ( nums[i]  , max[i-1]*nums[i]  , min[i-1]*nums[i] );
			min[i] = GETMIN ( nums[i]  , max[i-1]*nums[i]  , min[i-1]*nums[i] );
		}
		result = max[i]>result? max[i] : result;
	}
    free(max);
    free(min);
    return result;
}
```