### 解题思路
代码：
分情况讨论：
* 1.数组中全是小于9的数，进行digits[i] = digits[i] + 1，通过digits[i] % 10 != 0判断，对10取余不为0，说明肯定是小于9的数，那么就直接输出。
* 2.数组中有某一位数9，但是不全为9，例如：1239。那么当遍历到3这个数的时候，如果不加处理则会输出12410，不满足题目要求，所以增加for循环，进行遍历，将之前的数置为0
* 3.数组中的数全是9，那么就需要进一位，但是数组明显空间不够，所以动态分配内存的时候就要多开辟一位。只需要将数组首位设为1，其他为全部置为0，返回即可。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){

    for (int i = digitsSize - 1; i >= 0; i--) {

		digits[i] = digits[i] + 1;
		if (digits[i] % 10 != 0) {

			for (int j = i; i < digitsSize - 1; i++) {

				digits[i + 1] = 0;
			}

			* returnSize = digitsSize;
			return digits;
		}
	}

	int *result = (int*)malloc(sizeof(int*) * digitsSize + 1);

	result[0] = 1;
	for (int i = 1; i < digitsSize + 1; i++) {

		result[i] = 0;
	}
    
    * returnSize = digitsSize + 1;
	return result;
}
```