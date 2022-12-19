典型的**位运算**例题。
如题，假设有数组**nums=[1, 2, 3]**，数组长度为3，则一共有2^3-1个组合（不包括空集），因此依次按位进行**与**运算
  -：    1  2  3
  1：  0  0  1 —> [1] 
  2：  0  1  0 —> [2] 
  3：  0  1  1 —> [1, 2] 
  4：  1  0  0 —> [3] 
  5：  1  0  1 —> [1, 3]
  6：  1  1  0 —> [2, 3]
  7：  1  1  1 —> [1, 2, 3]
在上面7个不等长的列表中，每一个列表都需要循环3次，也就是数组的长度，这是因为要与数组的每一位进行与运算，当运算结果为1时，将这一位加入到该列表中。

```
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums)
{
	// 异常检测
	if (nums.empty() || nums.size() <= 0)
		return {};

	int nLength = nums.size();
	int N = pow(2, nums.size());
	vector<vector<int>> arr(N);

	for (int i = 1; i <= N; ++i)
	{
        // 每一次都复位到0x01
		int temp = 0x01;
		for (int j = 0; j < nLength; ++j)
		{
			if (i & temp)
				arr[i - 1].push_back(nums[j]);
			temp = temp << 1;
		}
	}

	return arr;
}

int main()
{
	vector<int> nums = { 1, 2, 3, 4 };

	vector<vector<int>> arr = subsets(nums);

	for (int i = 0; i < arr.size(); ++i)
	{
		cout << i + 1 << ": " << "\t";
		for (int j = 0; j < arr[i].size(); ++j)
			cout << arr[i][j] << " ";
		cout << endl;
	}

	return 0;
}
```
