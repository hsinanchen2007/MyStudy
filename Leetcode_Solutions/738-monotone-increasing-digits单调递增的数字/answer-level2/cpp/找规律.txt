### 解题思路
![image.png](https://pic.leetcode-cn.com/b4b66ec9251fdcc6d373d712ad0c268f6de28be7d7b90ed29e60c7b19ecaf833-image.png)


### 代码

```cpp
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
    int digi[10];
	int tpn=N;
	int cnt = 0;
	while (tpn)
	{
		digi[cnt++] = tpn % 10;
		tpn /= 10;
	}
	int up = -1;
	for (int i = cnt - 1; i >= 1; i--)
	{
		if (up == -1)
			if (digi[i] > digi[i - 1])
				up = i;
	}
	int res;
	if (up != -1)
	{
		for (int i = up + 1; i < cnt; i++)
			if (digi[i] == digi[up])
				up = i;
		digi[up]--;
		for (int i = up - 1; i >= 0; i--)
			digi[i] = 9;
		res = 0;
		for (int i = 0; i < cnt; i++)
			res += digi[i] * pow(10, i);
	}
	else res = N;
	return res;
    }
};
```