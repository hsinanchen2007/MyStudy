![image.png](https://pic.leetcode-cn.com/059215f5990f6e129e8a89aa5895e2eaeaa2720c4377b90ecfd80cdee58b3e95-image.png)
### 解题思路
滑动窗口，但是我对我的效率不是很满意，哪里写的不好，请大佬指教


### 代码

```cpp
class Solution {
public:
    struct Info{
        int val;
        int mark;
        Info():val(1), mark(0){}
    };

    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, Info> wordMap;
        vector<int> ret;
        if(s.size() == 0 || words.size() == 0 || s.size() < words[0].size())
            return ret;

        int len = words[0].size();

        for(auto i = 0; i < words.size(); ++i){
            if(wordMap.find(words[i]) == wordMap.end()){
                wordMap.insert(pair<string,Info>(words[i], Info()));
            }else{
                wordMap[words[i]].val++;
            }
        }

        for(int i = 0; i < len; ++i){
            int begin = i, end = begin + words.size() * len, count = 0; 
            if(end > s.size()) break;
            
            if(begin != 0){
                //clean memory
                for(auto it = wordMap.begin(); it != wordMap.end(); ++it){
                    it->second.mark = 0;
                }
            }
            //init window
            int p = begin;
            while(p < end){
                string key = s.substr(p, len);
                if( wordMap.find(key) != wordMap.end()){
                    if(wordMap[key].mark == wordMap[key].val){
                        count--;
                        wordMap[key].mark++;
                    }else{
                        wordMap[key].mark++;
                        if(wordMap[key].mark == wordMap[key].val) count++;
                    }
                }
                p = p + len;
            }

            if(count == wordMap.size()) ret.push_back(begin);

            //move window, every step we can move one word
            while(end + len <= s.size()){
                //remove head
                string key = s.substr(begin, len);
                if(wordMap.find(key) != wordMap.end()){
                    if( wordMap[key].mark == wordMap[key].val ){
                        count--;
                        wordMap[key].mark--;
                    }else{
                        wordMap[key].mark--;
                        if(wordMap[key].mark == wordMap[key].val) count++;
                    }
                }

                //insert tail
                key = s.substr(end, len);
                if(wordMap.find(key) != wordMap.end()){
                    if( wordMap[key].mark == wordMap[key].val ){
                        count--;
                        wordMap[key].mark++;
                    }else{
                        wordMap[key].mark++;
                        if(wordMap[key].mark == wordMap[key].val) count++;
                    }
                }
            
                begin = begin + len;
                end = end + len;
                //count ok?
                if(count == wordMap.size()) ret.push_back(begin);
            }
        }

        return ret;
    }
};
```