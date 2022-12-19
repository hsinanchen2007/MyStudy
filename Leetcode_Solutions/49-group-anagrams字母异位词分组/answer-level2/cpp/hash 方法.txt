```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> str_map;
        vector<vector<string>> result;
        for(int i = 0; i < strs.size(); i++)
        {
            string str_temp = strs[i];
            sort(str_temp.begin(), str_temp.end());
            if(str_map.find(str_temp) == str_map.end())
            {
                vector<string> item;
                str_map[str_temp] = item;
            }
            str_map[str_temp].push_back(strs[i]);
        }
        map<string, vector<string>>::iterator it;
        for(it = str_map.begin(); it != str_map.end(); it++)
        {
            result.push_back((*it).second);
        }
        return result;
    }
};
```
