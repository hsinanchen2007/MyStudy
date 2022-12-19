执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :5.8 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
	int guessNumber(int n) 
	{
		int i = 1, j = n;
		int t;
		while (i <= j)
		{
			t = i+(j - i) / 2;//不能写为(i+j)/2,会溢出
			if (guess(t) == 0)
				return t;
			else
				if (guess(t) == 1)
				
					i = t + 1;
				else
					j = t - 1;
		}
		return -1;//未找到
	}
};
```