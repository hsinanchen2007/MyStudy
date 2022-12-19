### 解题思路
用 flag 表示当前数字的位数，a 表示当前位数的最大值，flag=1时，a=10,flag=2时,a=100
### 代码

```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
    int flag = 1;
	vector<int> v;
	int num = 1;
	int a = 10;
	while (flag <= n)
	{
		v.push_back(num);
		num++;
		
		if (num % a == 0)
		{
			flag++;
			
		}
		a = pow(10, flag);
	}

	return v;
    }
};
```