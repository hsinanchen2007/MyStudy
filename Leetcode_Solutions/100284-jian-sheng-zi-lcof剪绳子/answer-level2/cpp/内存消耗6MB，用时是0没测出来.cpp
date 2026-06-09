### 解题思路
主要部分就是n分为m段后算出最大乘积来，切分部分就是一个遍历的本办法，本来想看数学思路怎么直接算出来，没想到代码运行这么快
算出最大乘积的办法也很简单，这个和正方形面积大于圆面积一样，先均分长度，多余的补上就是最大。

### 代码

```cpp
class Solution {
public:
	int cuttingRope(int n) {
		int m = 2, result = 0;
		while (m < n / 2)
		{
			result = max(result, product(n, m));
			++m;
		}
		return max(result, product(n, m));
	}
private:
	int product(int n, int m)
	{
		int result = 1;
		vector<int>temp(m, n / m);
		for (int i = 0; i < n % m; ++i)
		{
			temp[i] += 1;
		}
		for_each(temp.begin(), temp.end(), [&](int& value) {result *= value; });
		return result;
	}
};
```