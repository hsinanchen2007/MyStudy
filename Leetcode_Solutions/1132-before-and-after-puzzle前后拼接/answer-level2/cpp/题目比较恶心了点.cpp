```c++ []
class Solution {
public:
    std::vector<std::string> split(const std::string& s, char delimiter)
    {
       std::vector<std::string> tokens;
       std::string token;
       std::istringstream tokenStream(s);
       while (std::getline(tokenStream, token, delimiter))
       {
          tokens.push_back(token);
       }
       return tokens;
    }
    
    string connect(vector<string> & words){
        string ans;
        
        if(words.size() == 1){
            ans += words[0];
            return ans;
        }
        
        for(int i = 0;i < words.size()-1; ++i){
            ans += words[i] + ' ';
        }
        ans += words[words.size()-1];
        
        return ans;
    }

    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        int n = phrases.size();
        vector<vector<string>> words(n,vector<string>());
        unordered_map<string,vector<int>> head;
        set<string> res;
        
        for(int i = 0;i < n; ++i){
            words[i] = split(phrases[i],' ');
            head[words[i][0]].push_back(i);
        }
        for(int i = 0;i < n; ++i){
            string tail = words[i][words[i].size()-1];
            for(int j = 0;j < head[tail].size(); ++j){
                int k = head[tail][j];
                if( k == i){
                    continue;
                }
                vector<string> merge;
                merge.insert(merge.end(),words[i].begin(),words[i].end());
                merge.insert(merge.end(),words[k].begin()+1,words[k].end());
                res.insert(connect(merge));
            }
        }
        
        vector<string> ans;
        for(auto w : res){
            ans.push_back(w);
        }
        
        return ans;
    }
};
```
