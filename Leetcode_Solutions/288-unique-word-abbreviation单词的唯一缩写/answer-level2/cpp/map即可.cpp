hashmap为索引存储字符串即可。

```
class ValidWordAbbr {
public:
    static string addr(string key){
        string ans;
        if(key.size() > 2){
            ans.push_back(key[0]);
            ans = ans + to_string(key.size()-2);
            ans.push_back(key.back());
        }else{
            ans = key;
        }
        
        return ans;
    }
        
    ValidWordAbbr(vector<string>& dictionary) {
        set<string> words;
        
        for(auto d : dictionary){
            words.insert(d);
        }
        
        for(auto w : words){
            dict[addr(w)].push_back(w);
        }        
    }
    
    bool isUnique(string word) {
        string key = addr(word);
        
        if(dict.count(key)){
            if(dict[key].size() > 1){
                return false;
            }else{
                if(dict[key][0] == word){
                    return true;
                }else{
                    return false;
                }
            }
        }
        
        return true;
    }
private:
    map<string,vector<string>> dict;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
```