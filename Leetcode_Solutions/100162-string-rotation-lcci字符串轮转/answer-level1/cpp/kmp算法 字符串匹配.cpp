    我发现大家都执着于用java的contain()函数或者c++的strstr()函数。我觉得作为一个练习算法的题目，不应该总是想到调用别人的函数，而是应该尝试自己写一个字符串匹配的函数，虽然自己的函数不见得比别人的现成的函数好用，并且也是重复造轮子，但是自己写有助于加深自己对于某些经典算法的理解。

我在本题中使用的是kmp算法，是一个经典的字符串匹配算法。这个算法的详解是：[https://blog.csdn.net/hanzhen7541/article/details/104155275](https://blog.csdn.net/hanzhen7541/article/details/104155275) 

最终实现的算法时间复杂度是O(2 * m) = O(m),空间复杂度是O(m).如果用正常的匹配算法复杂度应该是O(m^2)
```
class Solution {
public:
	bool isFlipedString(string s1, string s2) {
		if (s1.size() != s2.size()) return false;
		/*这是最朴素的字符串匹配,时间复杂度O(m^2),空间复杂度O(1)*/
		// return match(s1, s2);
		/*kmp算法匹配，时间复杂度是O(m * 2) = O(m),空间复杂度是O(m)*/
		vector<int> next;
		getnext(s1, next);
		return match_kmp(s1, s2, next);
	}
	bool match(string s1, string s2){
		s2 = s2 + s2;
		int i = 0;
		int j = 0;
		while (i < s1.size() && j < s2.size())
		{
			if (s1[i] == s2[j]){
				i++;
				j++;
			}
			else{
				i = 0;
				j = j - i + 1;
			}
		}
		return i == s1.size();
	}
	/*
	求next数组，注意next[j]表示的是索引j前面的最大的前缀后缀相同的子串长度
	*/
	void getnext(string s1, vector<int> &next){
		next.push_back(-1);
		int k = -1;
		for (int j = 1; j < s1.size(); j++){
			while (k != -1 && s1[j - 1] != s1[k])
			{
				//这一步是关键
				k = next[k];
			}
			k++;
			next.push_back(k);
		}
	}
	bool match_kmp(string s1, string s2, vector<int> next){
		s2 = s2 + s2;
		int i = 0;
		int j = 0;
		while (i < (int)s1.size() && j < s2.size())
		{
			if (i == -1 || s1[i] == s2[j]){
				i++;
				j++;
			}
			else{
				i = next[i];
			}
		}
		return i == s1.size();
	}
	
};
```
