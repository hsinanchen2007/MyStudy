目标是找到
1、长度最长 
2、只出现过一次 
3、并且不是任何其它字符串子序列 
的字符串，然后返回其长度。
```
class Solution {
public:
	int findLUSlength(vector<string>& strs) {
		multiset<string> myset;
		for (auto s : strs) {
			myset.insert(s);
		}
		
		sort(strs.begin(), strs.end(), [](string s1, string s2) {return s1.size() > s2.size(); });//按照从长到短排列
		for (int i = 0; i < strs.size(); ++i) {//从长到短寻找
			bool flag = 0;
			if (myset.count(strs[i]) == 1) {//如果该string只出现过一次
				flag = 1;
				for (int j = 0; j < i; ++j) {//并且不是任何其他string的子序列
					if (judgestr(strs[j], strs[i])) {
						flag = 0;
						break;
					}
				}
			}
			if (flag) {
				return strs[i].size();//返回该string的长度
			}
		}
		return -1;
	}
private:
	bool judgestr(string s1, string s2) {//判断s2是否是s1的子序列
		int cnt = 0;
		for (int i = 0; i < s1.size(); ++i) {
			if (s1[i] == s2[cnt]) cnt++;
			if (cnt == s2.size()) return 1;
		}
		return 0;
	}
};
```

