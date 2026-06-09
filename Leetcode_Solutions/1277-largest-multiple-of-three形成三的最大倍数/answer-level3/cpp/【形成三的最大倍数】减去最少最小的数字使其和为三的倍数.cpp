### 思路
1. 各个位数相加的和，是三的倍数，那么这个数一定是三的倍数
2. 如果和取模为 1 ，可以减去一个最小的取模为 1 的数字（1 4 7），或者两个取模为 2 的数字（2 5 8）
3. 如果和取模为 2 ，与上面相反，减去一个最小的取模为 2 的数字，或者两个最小的取模为 1 的数字
4. 减一个数字相当于减了一位，为了使数字最大，当然是先优先减一个数字，从小到大。如果不行，再减两个数字
5. 使用一个 `vector<int> cnt(10, 0)` 或者 `cnt[10]` 来把各个数字个数记录，方便减数
6. 减数之后就按照数字从大到小依次添加进去即可
7. 注意全 0 的数字只返回一个 0

### 答题
```C++
class Solution {
public:
	bool deleteNum(vector<int>& cnt, int n)
	{
		for (int i = n; i <= 9; i += 3)
		{
			if (cnt[i] == 0) continue;
			cnt[i]--;
			return true;
		}
		return false;
	}

	string largestMultipleOfThree(vector<int>& digits)
	{
		vector<int> cnt(10, 0);
		int sum = 0;
		for (auto& d : digits)
		{
			sum += d;
			cnt[d]++;
		}

		if (sum % 3 != 0)
		{
			int a = sum % 3;
			int b = 3 - a;
			if (!deleteNum(cnt, a))
			{
				deleteNum(cnt, b);
				deleteNum(cnt, b);
			}
		}
		if (cnt[0] != 0 && all_of(cnt.begin() + 1, cnt.end(), [](const int& a) { return a == 0; })) return "0";

		string ans;
		for (int i = cnt.size() - 1; i < cnt.size(); i--)
		{
			while (cnt[i]-- != 0)
			{
				ans += to_string(i);
			}
		}
		return ans;
	}
};
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

