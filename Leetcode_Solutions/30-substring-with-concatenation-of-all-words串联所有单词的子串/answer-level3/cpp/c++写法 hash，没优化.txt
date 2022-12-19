```
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //hahs
        if(words.size() == 0){
            return {};
        }
        int len_word = words[0].length();
        unordered_map<string ,int>mp;
        unordered_map<string ,int>mp2;

        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
            mp2[words[i]]++;

        }
        vector<int>ans ;
        int jump = words.size() * len_word;
        int len = s.length();
        for(int i=0;i+jump-1<len;i++){ // 第一次交，漏了i+jump-1<len。疏忽大意
            int bug = 0;
            for(int j=i;j<jump+i;j+=len_word){
                string tmp = s.substr(j,len_word);
                if(!mp[tmp]){
                    bug =1;
                    break;
                }
                mp[tmp]--;
            }
            if(!bug){
                ans.push_back(i);
            }
            mp = mp2;// 恢复hash。
        }
        return ans;
        
    }
};
```
