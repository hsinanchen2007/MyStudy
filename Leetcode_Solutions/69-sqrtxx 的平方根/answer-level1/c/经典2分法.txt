### 解题思路
此处撰写解题思路

### 代码

```c
/*
1.经典2分法，折半
2.guess条件简单
3.注意各种超时，区间差1，就超时
*/
bool Guess(int mid, int x)
{
	return (long long)mid * mid <= x;
}

int mySqrt(int x)
{
    int left = 0;
	long long right = (long long)x + 1; // [0, x + 1)
	int mid;
	int ret = 0;
	while (left < right) {
		mid = (left + right) / 2;
		if (Guess(mid, x)) {
            ret = mid;
            left = mid + 1;
		} else {
			right = mid;
		}
	}
	return ret;
}
```