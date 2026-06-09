### 解题思路
我之前是直接遍历1到nums[i]求因数，后来到某个测试用例超出时间限制，于是我改变了遍历方式，从1到sqrt(nums[i])，时间问题就解决了。

### 代码

```cpp
class Solution {
public:
	int sumFourDivisors(vector<int>& nums) {
		int s = 0;

		for(int i = 0; i < nums.size(); i++) {
			vector<int> divisor;
			for(int j = 1; j <= sqrt(nums[i]); j++) {
				if (nums[i] % j == 0) {
					divisor.push_back(j);
                    if(nums[i]/j!=j)
                        divisor.push_back(nums[i]/j);
				}
			}
			int sum = accumulate(divisor.begin(), divisor.end(), 0);

			if (divisor.size() == 4) {
				s += sum;
			}
		}

		return s;
	}
};
```