### 解题思路
代码非常的清楚，digitOfOne表示一个数中存在的1的个数，numOfOne求n以内的1的个数。numOfOne函数中return部分即为状态转移的递归关系

### 代码

```cpp
class Solution {
public:
int digitOfOne(int n)
{
	int count = 0;
	for (int i = 0; n > 0; i++)
	{
		if (n % 10 == 1)
			count++;
		n /= 10;
	}
	return count;
}
int numOfOne(int n)
{
	if (n == 1)
		return 1;
	if (n == 0)
		return 0;
	if (n < 0)
		return 0;
	return (n % 10 + 1)*digitOfOne(n / 10) + (n % 10 > 0 ? 1 : 0) + (n / 10) + 10 * numOfOne(n / 10-1);
}
    int countDigitOne(int n) {
        return numOfOne(n);
    }
};
```