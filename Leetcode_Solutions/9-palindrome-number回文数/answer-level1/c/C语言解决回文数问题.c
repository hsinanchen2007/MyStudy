### 解题思路
当x为负数时，根据题意肯定不是回文数，当为非负数时，可以先定义一个数组用来存储输入数据的各个位，然后利用循环将x的各个位取下来，然后使用for循环，从两头开始比较数组的对应位置的元素是否相同，若不同则返回false。

### 代码

```c
bool isPalindrome(int x) {
    if(x<0)
        return 0;
	int a[1000];
	int i = 0;
	int left, right;
	while (x != 0)
	{
		a[i++] = x % 10;
		x /= 10;
	}
	left = 0;
	right = i - 1;
	while (left < right)
	{
		if (a[left] != a[right])
		{
			return 0;
		}
		left++;
		right--;
	}
	return 1;
}
```