### 思路
一开始是从数学角度，对各种情况分类讨论。后来发现，不如直接对字符串进行相加比较。

### 算法的正确性
本题难在算法的正确性证明。此处引入“逆序对”的概念。
```
设 A 为一个有 n 个数字的有序集 (n>1)，其中所有数字各不相同。
如果存在正整数 i, j 使得 1 ≤ i < j ≤ n 而且 A[i] > A[j]，则 <A[i], A[j]> 这个有序对称为 A 的一个逆序对，也称作逆序数。
```
而此处的逆序对，指存在i>j,使得v[i]+v[j]>v[j]+v[i].
其实，可以简单的想：
如果存在一对逆序对，那么该逆序对交换顺序后必会产生更大的数，则此时的数并不是最大的。
若可保证v数组内，任意相邻两个v[i]\v[j]都不是逆序对，则此时产生的数是最大的。

### int转string方法总结比较：
1. 法一：itoa函数（Windows）
	缺点：非C/C++标准，可移植性不好
2. 法二：std::to_string()
	优点：快！
3. 法三：借助stringstream
	缺点：慢。
4. 法四：C库函数sprintf()
	优点：可以转换各种进制的数。
	缺点：需要先分配足够的char数组。


### 代码

```cpp
bool cmp(string a, string b)//直接相加比较
{
	return a+b > b+a;
}

class Solution {
public:
string largestNumber(vector<int>& nums) {
	vector<string>v;
	for (int i = 0; i < nums.size(); i++)
	{
		string temp = to_string(nums[i]);//比用stringstream要快很多！
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);
	string ret;
	for (int i = 0; i < v.size(); i++)
	{
		ret += v[i];
        if (v[0] == "0")//考虑全零的情况
			break;
	}
	return ret;

}
};
```