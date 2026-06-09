### 解题思路
1. 用sub string实时更新不含重复元素的集合
2. 每次检索到重复元素后，删除sub string中<=ind的元素，并且更新max_len
3. 当“哨兵”index达到原始s的上界，返回max_len

### 代码

```cpp
class Solution {
public:
	int lengthOfLongestSubstring(string s){
		if(!s.size()) return 0;
		if(s.size() == 1) return 1;
		int max_len = 0;
		size_t start_ind = 0;
		string s_truc;
		while(start_ind <= (s.size() - 1)){
			char ch_target = s[start_ind];
			auto ind = std::find(s_truc.begin(), s_truc.end(), ch_target);
			if(ind == s_truc.end()){
				s_truc += ch_target;
				max_len = std::max(max_len, static_cast<int>(s_truc.size()));
			}else{
				max_len = std::max(max_len, static_cast<int>(s_truc.size()));
				s_truc = s_truc.substr(ind+1-s_truc.begin(), s_truc.size()-1);
//				cout << "Before +ch_target, s_truc = " << s_truc << endl;
				s_truc += ch_target;
//				cout << "start_ind = " << start_ind << " Found dup, and s_truc = " << s_truc << endl;
			}
			start_ind++;
//			cout << "start_ind = " << start_ind << endl;
		}

		return max_len;
	}
};
```