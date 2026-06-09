### 解题思路
周赛的时候暴力递归挂掉了。。。
只需要关注的字符数为'a'、'e'、'i'、'o'、'u'这五个字符，而且他们的状态要么是基数，要么是偶数，显然就可以用位运算来保存信息。

这道题关键点是如果计算子串是否满足条件，也就是子串是否状态state为0。
这里有个点是如果当前的state和前面第一次出现的state相同，那么当前满足条件的最长子串就是当前的长度减去第一次出现该state的长度（把元音字母抵消掉。。。），这样就可以只需要遍历一次就可以解决问题。

### 代码

```cpp
class Solution {
public:
    void Initialize(map<char, int>& chrMap)
    {
        chrMap['a'] = 0;
        chrMap['e'] = 1;
        chrMap['i'] = 2;
        chrMap['o'] = 3;
		chrMap['u'] = 4;
    }
	int GetWordIndex(map<char, int>& chrMap, char chr) 
	{
		if (chrMap.find(chr) != chrMap.end()) {
			return chrMap[chr];
		}
		return -1;
	}
    int findTheLongestSubstring(string s) {
        map<char, int> chrMap;
        Initialize(chrMap);
		unsigned int state = 0;
		map<unsigned int, int> stateMap;
		stateMap[0] = -1;
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			int index = GetWordIndex(chrMap, s[i]);
			if (index != -1) {
				state ^= (1 << index);
			}
			if (stateMap.find(state) != stateMap.end()) {
				ans = max(ans, i - stateMap[state]);
			} else {
				stateMap[state] = i;
			}
		}
		return ans;
    }
};
```