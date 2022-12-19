n = 1 时为10；
n = 2 时为 f(1) + 9*9  （首位不能取零，后面不能与前面重复）；
n = 3 时为 f(2) + 9*9*8;
...
f(n) = f(n-1) + 9*9*8*7*……（n个数相乘）

虽然题目没有考虑 n>10 的情况
为了解题的严谨性，应该考虑一下

```
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
    if (n == 0)
	{
		return 1;
	}

	if (n == 1)
	{
		return 10;
	}
	
	int pre = 10;
	int x = 9;
	int i = 1;

	while (i < n && i < 10)
	{
		x = x * (10 - i);

		pre = pre + x;
        
        i++;
	}

	return pre;
    }
};
```

![357 计算各个位数不同的数字个数.png](https://pic.leetcode-cn.com/40674df54f3671107e2f67ea5d9e3713a872decedd203d460c3526adc7aba9aa-357%20%E8%AE%A1%E7%AE%97%E5%90%84%E4%B8%AA%E4%BD%8D%E6%95%B0%E4%B8%8D%E5%90%8C%E7%9A%84%E6%95%B0%E5%AD%97%E4%B8%AA%E6%95%B0.png)

