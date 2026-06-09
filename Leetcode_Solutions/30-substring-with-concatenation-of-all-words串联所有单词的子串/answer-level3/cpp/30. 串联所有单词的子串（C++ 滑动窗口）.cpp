# 30. 串联所有单词的子串
**代码实现：**
```
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> rst;
        if((s == "") || (words.size() == 0)){
			return rst;
		}
		
		int word_num = words.size();
		int word_one = words[0].size();
		int window_len = word_one * word_num;
        map<string,int> m_map;
        map<string,int>::iterator iter;

        for(auto word :  words){
			iter = m_map.find(word);
			if(iter != m_map.end()){
				(iter->second)++;
			}else{
				m_map.insert({word,1});
			}
		}

        for(int i = 0; i < s.size()-window_len+1; ++i){
			map<string,int> t_map = m_map;
			string subword = s.substr(i,window_len);
			for(int j = 0; j < word_num; ++j){
				string word_item = subword.substr(j*word_one,word_one);
				if((iter=t_map.find(word_item)) != t_map.end()){
					if(iter->second == 1){
						t_map.erase(word_item);
					}else{ 
						--(iter->second);
					}
				}else{
					break;
				}
			}
			if(t_map.empty()){
				rst.push_back(i);
			}
		}

        return rst;
    }
};
```
