### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
    	vector<int> times(26, 0);
    	for(size_t i=0;i<s.size();++i){
    		times[s[i]-'a']++;
//    		cout << "s[" << i << "]=" << s[i] << " times[" << s[i]-'a'<<"]=" << times[s[i]-'a'] << endl;
    	}
    	for(size_t i=0;i<s.size();++i){
    		if(times[s[i]-'a'] == 1){
    			return i;
    		}
    	}
    	return -1;
    }
//    //下面是我用的通法——本体的注意事项中假设给定的字符串只包含小写字母（给了众多垃圾投机取巧的机会）
//    int firstUniqChar(string s) {
//    	string s_bak(s);
//    	set<char> set_dup;
//    	while(s.size()){
//    		auto ind = find(s.begin()+1, s.end(), s[0]);
//    		if(ind == s.end()){
//    			auto target = find(s_bak.begin(), s_bak.end(), s[0]);
//    			auto ind_dup = find(set_dup.begin(), set_dup.end(), static_cast<char>(s[0]));
//    			if(ind_dup == set_dup.end()) {
//    				return target - s_bak.begin();
//    			}else{
//    				s.erase(s.begin());
//    			}
//    		}else{
//    			set_dup.insert(static_cast<char>(s[0]));
//    			s.erase(ind);
//    			s.erase(s.begin());
////    			for(auto& iter:set_dup){
////    				cout << iter << " ";
////    			}
////    			cout << endl;
//    		}
//    	}
//    	return -1;
//    }
};
```