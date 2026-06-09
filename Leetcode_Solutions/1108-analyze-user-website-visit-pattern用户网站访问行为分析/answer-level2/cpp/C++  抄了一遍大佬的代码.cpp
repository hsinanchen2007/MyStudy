
```
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        vector<string> cp = website;
        sort(cp.begin(), cp.end());
        unordered_map<string, int> nameMap;
        unordered_map<int, string> idMap;
        int count = 0;
        for (string& s: cp) {
            if (!nameMap.count(s)) {
                nameMap[s]  = count;
                idMap[count] = s;
                count++;
            }
        }

        unordered_map<string, vector<pair<int, int>>> data;
        for (int i = 0; i < username.size(); ++i) {
            data[username[i]].push_back({timestamp[i], nameMap[website[i]]});
        }
        for (auto& p : data) {
            sort(p.second.begin(), p.second.end(), compair);
        }

        unordered_map<string, int> countMap;
        for (auto& p : data) {
            unordered_set<string> tmpSet;
            int psz = p.second.size();
            for (int i = 0; i < psz; ++i) 
                for (int j = i + 1; j < psz; ++j) 
                    for (int k = j + 1; k < psz; ++k)
                        tmpSet.insert({p.second[i].second,
                                        p.second[j].second, 
                                        p.second[k].second});    
            for (string s: tmpSet) countMap[s]++;
        }

        vector<pair<string, int>> vec;
        for (auto& p : countMap) {
            vec.push_back(p);
        }
        sort(vec.begin(), vec.end(), compair2);
        vector<string> ans;
        for (int cnt : vec.front().first) {
            ans.push_back(idMap[cnt]);
        }
        return ans;
    }

    static bool compair(pair<int, int>&a, pair<int, int>& b) {
        return a.first < b.first;
    }

    static bool compair2(pair<string, int>&a, pair<string, int>&b) {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    }
};
```
