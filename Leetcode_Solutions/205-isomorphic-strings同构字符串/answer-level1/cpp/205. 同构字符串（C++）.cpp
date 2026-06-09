```
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> s2t;	//记录s到t的映射
		map<char,char> t2s;	//记录t到s的映射
		map<char,char>::iterator iter;	
		
		//题目给出t与s串等长，只需判断s串下标
		for(int i = 0; i < s.size(); ++i){
			//判断s到t串是否存在在合法映射
			if( (iter = s2t.find(s[i])) != s2t.end() ){
				if(iter->second != t[i]){
					return false;
				}
			}
			//判断t到s串是否存在在合法映射
			if((iter = t2s.find(t[i])) != t2s.end()){
				if(iter->second != s[i]){
					return false;
				}
			}
			//都不存添加映射
			s2t.insert({s[i],t[i]});
			t2s.insert({t[i],s[i]});
		}
		return true;
    }
};
```
