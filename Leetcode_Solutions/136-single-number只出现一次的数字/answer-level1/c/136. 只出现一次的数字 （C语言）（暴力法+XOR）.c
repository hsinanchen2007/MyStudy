# 136. 只出现一次的数字 
**思路一：（暴力法）**
直接遍历数组中的每一个数，再观察数组中的其他数是否重复。
```
//暴力破解法
int singleNumber(int* nums, int numsSize){
	if( numsSize <= 1 ){
		return nums[0];
	}
	int i,j;
	int symbol = 0;
	for( i = 0; i < numsSize; ++i ){
		symbol = 0;
		for( j = 0; j < numsSize; ++j ){
			if( i == j ){
				continue;
			}
			if( nums[i] == nums[j] ){
				symbol = 1;
				break;
			}
		}
		if( symbol == 1 ){
			continue;
		}else{
			break;
		}
	}
	return nums[i];
}

```

**思路二：（XOR）**
使用亦或的方式，由于这组数据中除了单独出现的一个数据，其他数据都是成对出现的。
  - 一个数与自身异或(XOR)为0。

所以将所有数组中所有数遍历XOR后得到的就是单独出现的数值。
```
int singleNumber(int* nums, int numsSize){
	int XOR = nums[0];
	int i;
	for( i = 1; i < numsSize; i++ ){
		XOR = XOR ^ nums[i];
	}
	return XOR;
}
```

