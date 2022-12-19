思路：
1、将vector<int>转变为vector<string>
2、快速排序，将vector<string>从大到小排序。
   判断A、B大小规则：比较A+B和B+A那个大
3、将排完序的vector<string>连起来即结果；
   注意：若开头为‘0’，则输出‘0’；例子：输入0，0；输出：0
改进：
无需将vector<int>转变，直接排序vector<int>
关键：如何判断a和b谁先谁后？
```
vector<int> ve;
using T = decltype(ve.begin());

class Solution {
public:
    string largestNumber(vector<int>& nums);
private:
    bool cmp(int a, int b);  //比较a、b
    T quick(T beg, T end);
    void QuickSort(T beg, T end);
};

bool Solution::cmp(int a, int b)  //比较a、b
{
	string a_str = std::to_string(a);
	string b_str = std::to_string(b);
	string str1 = a_str + b_str;
	string str2 = b_str + a_str;
	return str1 > str2;
}

T Solution::quick(T beg, T end)
{
	T ok = beg;
	T p = beg + 1;
	while (p != end)
	{
		if (cmp(*p, *beg))
		{
			ok++;
			if (ok != p)
				swap(*ok, *p);
			p++;
		}
		else
			p++;
	}
	swap(*ok, *beg);
	return ok;
}

void Solution::QuickSort(T beg, T end)
{
	if (beg == end || beg + 1 == end)
		return;
	T pivotpoint = quick(beg, end);
	QuickSort(beg, pivotpoint);
	QuickSort(pivotpoint + 1, end);
}

string Solution::largestNumber(vector<int>& nums)
{
	QuickSort(nums.begin(), nums.end());
	string out;
	if (*(nums.begin()) == 0)
		out = "0";
	else
	{
		for (auto i : nums)
			out += std::to_string(i);
	}
	return out;
}

```


