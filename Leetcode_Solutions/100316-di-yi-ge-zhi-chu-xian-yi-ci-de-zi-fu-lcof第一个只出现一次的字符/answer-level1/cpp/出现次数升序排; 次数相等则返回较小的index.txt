### 解题思路
执行用时 :104 ms, 在所有 C++ 提交中击败了15.19% 的用户
内存消耗 :31 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        if(s.compare("") == 0) return ' ';
    	map<char, pair<int, vector<int>>> record;
    	for(size_t i=0;i<s.size();++i){
    		record[s[i]].first++;
    		record[s[i]].second.push_back(i);
    	}
    	vector<pair<char, pair<int, vector<int>>>> v_record(record.begin(), record.end());
    	std::sort(v_record.begin(), v_record.end(), [](const pair<char, pair<int, vector<int>>>& l, const pair<char, pair<int, vector<int>>>& r){

    		if(l.second.first == r.second.first){
    			return l.second.second[0] < r.second.second[0];
    		}else{
    			return l.second.first < r.second.first;
    		}
    	});

    	return (v_record[0].second.first == 1) ? v_record[0].first : ' ';
    }
};
```