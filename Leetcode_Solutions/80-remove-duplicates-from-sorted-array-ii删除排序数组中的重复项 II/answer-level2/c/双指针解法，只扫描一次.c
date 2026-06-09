设置参考指针s,用于记录快指针走过时的重复数
当快指针值与参考指针值相同，说明重复，只要重复次数小于等于2，则将慢指针值与快指针值相等。
如果快指针与参考指针的值不相等，将参考指针指向快指针，然后快指针再往前走
```
int removeDuplicates(int nums[], int numsSize)
{
	int* end = nums + numsSize;
	int* p = nums;
	int* q = nums;
	int* s = nums;
	while (p < end) {
		if (*p == *s) {
			if (p - s < 2) {
				*q = *p;
				*q++;
			} 
			*p++;
		} else {
			s = p;
		}
	}
    return q - nums;
}

```
