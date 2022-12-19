### 解题思路
此处撰写解题思路

### 代码

```cpp

class Solution {
public:
	int findNthDigit(int n) {
		if (n <= 9) return n;
		int count = 2;//计算n属于第几档
		vector<long long int> range = {0,10};
		long long int sum = 10;
		long long int i;
		for (int i = 2; i <= 12;i++) {
			range.push_back(i*9*pow(10,i-1)+sum);
			sum = i * 9 * pow(10, i - 1) + sum;
		}
		int findIndex = 0;
		int sum2 = 0;
		for (int i = 0; i < range.size()-1;i++) {
			sum2 = range[i];
			if ((range[i]<=n)&&(range[i+1]>=n)) {
				findIndex = i;
				break;
			}
		}
		int haha = n - sum2;
		int h = haha / (findIndex + 1);
		int l= haha % (findIndex + 1);
		int base = pow(10, findIndex);
		int basePlush = base + h;
		vector<int> res;
		while (basePlush>0) {
			res.push_back(basePlush % 10);
			basePlush /= 10;
		}
		reverse(res.begin(), res.end());
		return res[l];
	}
};
```