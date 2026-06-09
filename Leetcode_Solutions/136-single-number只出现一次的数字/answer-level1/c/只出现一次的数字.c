### 解题思路
//在题解中找到的题解,理解了才发出来,作为自己以后的思路参照吧
//1.一个数与自身异或==0
//2.也就是说,数组中只要出现重复两次的数,那么这两个数被异或后就等于被抵消了,最后剩下的值肯定就是直出现过一次的数据
//3.xor运算：①a^a=0 ②a^0=a ③XOR 满足交换律和结合律
### 代码

```c
int singleNumber(int* nums, int numsSize)
{

	int k = nums[0];
	int i;
	for( i = 1; i < numsSize; i++ ){
		k = k ^ nums[i];
	}
	return k;
}
```