执行用时 :28 ms, 在所有 C++ 提交中击败了90.14%的用户
内存消耗 :17.9 MB, 在所有 C++ 提交中击败了8.15%的用户

### 代码

```cpp
class NumArray{
private:
	vector<int> sumv;
public:
	NumArray(vector<int>& nums)
	{
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			sum += nums[i];
			sumv.push_back(sum);
		}
		//sumv.push_back();
	}
    int sumRange(int i, int j)
	{
		if (i == 0)
			return sumv[j];
		else
			return sumv[j] - sumv[i - 1];
	}
};
```