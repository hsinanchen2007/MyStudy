### 解题思路
有一个策略，就是首先找出具有k-1个不同差值绝对值的数组，剩下的数逐渐加一，则此时差值是1，正好可以达到差值绝对值有k个不同的可能取值，但是要分k的奇偶考虑：例如7，5是1，7，2，6，3，4，5.而7，4为7，1，6，2，3，4，5.我也是无意中发现的。可以通过例子和代码模拟以下。
![image.png](https://pic.leetcode-cn.com/72ead1ef60fd1dc1fdf69e925507d8a6f183579873cf9eb91d158edef2c9e4ca-image.png)


### 代码

```cpp
class Solution {
public:
    vector<int> constructArray(int n, int k) {
    vector<int>res;
	int dif = 0;
	int start, end, turn;
	if (k % 2 == 1)
	{
		start = 2;
		end = n;
		turn = 1;
		res.push_back(1);
	}
	else {
		start = 1;
		end = n-1;
		turn = 0;
		res.push_back(n);
	}
	while(dif<k-1)
		if (turn)
		{
			res.push_back(end--);
			turn = 0;
			dif++;
		}
		else {
			res.push_back(start++);
			turn = 1;
			dif++;
		}
	for (int i = start; i <= end; i++)
		res.push_back(i);
        return res;
    }
};
```