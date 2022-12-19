
//实在是改不出来了，突发奇想递归一下，我真的秀(卑微
```
class Solution {
public:
	bool Is(int N)
	{
		vector<int>arr;
		do
		{
			int a = N % 10;
			arr.push_back(a);
			N /= 10;
		} while (N);
		for (int i = 1; i < arr.size(); ++i)
		{
			if (arr[i - 1] < arr[i])
				return false;
		}
		return true;
	}
	int monotoneIncreasingDigits(int N) {
		if (Is(N))
			return N;
		int res = 0;
		int M = N;
		vector<int>arr;
		do
		{
			int a = M % 10;
			arr.push_back(a);
			M /= 10;
		} while (M);
		int a, b, i;
		a = 0, b = 1, i = 1;
		while (a <= b)
		{
			a = arr[arr.size() - i];
			b = arr[arr.size() - i - 1];
			i++;
			if (a > b)
				res += a * pow(10, arr.size() - i + 1) - 1;
			else
			{
				res += a * pow(10, arr.size() - i + 1);
			}
		}
		while (!Is(res))
			res = monotoneIncreasingDigits(res);
		return res;
	}

};
```
