解题思路

摩尔投票法，通过一个计数变量s，来观察哪一个数最后不是0即为majority;相同加，不相同减，变为0后换下一个。

C语言 代码

```c
int majorityElement(int* nums, int numsSize){
    int s = 1;
	int maj = nums[0];
	for (int i = 1; i < numsSize; i++) {
		if (maj == nums[i]){
			s++;
		}
		else {
			s--;
			
		}
		if (s == 0) {
			maj = nums[i + 1];
		}
	}
	return maj;

}
```