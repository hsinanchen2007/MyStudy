### 解题思路
首先自嘲一下这个标题hhh大家看看这个神奇思路就好
还是讲一讲自己的想法（以下想法如果有漏洞希望各位大佬及时指正，谢谢！）
+ 首先注意到要让整个数最小，肯定是首位越小的越放在前面。就给出的样例``[3,34,30,5,9]``而言，一旦有以3打头的数，那么5一定不会在第一个
+ 那么接下来的问题是首位相同的数如何排序呢？因为只要首位相同的那些数保证排列后最小，则拼接起来就是整体的最小值。但它们显然不是直接按照字典序进行排列的。那么反例出在哪里？发现如果以同一个数字开头的几个数，如果位数相同，则按字典序排列，如果位数不同，则不一定是按字典序排列。e.g.本例中答案是3033459
+ 我们发现这样一个现象：只考虑首位相同的那些数的排列最小值，则3,30,34可以看做33,30,34（我也解释不清楚为什么自己就突然这样想了，但似乎确实如此，因为3要是放在中间，接在后面的也一定是下一个数字的首位3，所以补一个首位3不会影响各自的顺序）。这样把位数补齐以后，就可以直接全局字典序排序了！（其实还有一点小bug，后面讲）
+ 于是贪心的策略是：首先将整个数字转化成字符串，找到字符串的最大长度，将所有字符串用首位补齐后根据字典序排序。最后将原字符串拼接起来。
+ 但是败在了最后一个测试点，一看发现测试样例是``[12,121]``,emmm看来之前考虑还是不周全，因为没有考虑补齐后字典序相同的情况``121 == 121``，这种情况下特殊处理一下就好，返回字符串相接的较小的那种顺序即可。（其实自己思考到这里，就应该能够想到正解里的简单解法了）
+ 下面就是AC的代码啦！

### 代码

```cpp
// 8ms
// 可能是因为目前提交记录太少了才双100%
class Solution {
public:
	string minNumber(vector<int>& nums) {
		string ans;
		vector<pair<string,string>> numstring;
		int maxLen = 0;
		string ss;
		for(auto num: nums){
			ss = to_string(num);
			numstring.push_back(make_pair(ss, ss));
			maxLen = max(maxLen, (int)ss.length());
		}
		for(auto& str: numstring){
			str.second.insert(str.second.end(),maxLen - str.first.size(), str.first[0]);
		}
		auto cmp = [](const pair<string, string>& a, const pair<string, string>& b){return (a.second < b.second)||(a.second==b.second && a.first + b.first < b.first + a.first); };
		sort(numstring.begin(), numstring.end(), cmp);
		for(auto str: numstring){
			ans += str.first;
		}
		return ans;
	}
};

```