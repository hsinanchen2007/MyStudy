还是先把strs内的每一串排序后输入到哈希表当中
然后再输出。


```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string,vector<string>> hashmap;
        for(auto s:strs){
            string temp=s;
            sort(temp.begin(),temp.end());
            hashmap[temp].push_back(s);

        }
        for(auto i:hashmap){
            res.push_back(i.second);
        }
        return res;

        
    }
};
```
