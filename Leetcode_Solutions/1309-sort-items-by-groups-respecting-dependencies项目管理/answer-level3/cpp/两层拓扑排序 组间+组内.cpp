```
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        map<int, vector<int>> groups;
        vector<int> group_ids;
        for(int i=0;i<group.size();i++) {
            if(group[i]==-1) group[i] -= i;
            if(groups[group[i]].empty()) group_ids.push_back(group[i]);
            groups[group[i]].push_back(i);
        }
        // group
        map<int, unordered_set<int>> gsub, isub;
        map<int, int> ginput, iinput;
        for(int i=0;i<n;i++) {
            if(beforeItems[i].empty()) continue;
            for(int j: beforeItems[i]) {
                // group相同时，处理group之间的排序
                if(group[j]!=group[i]) {
                    if(gsub[group[j]].count(group[i])==0) {
                        gsub[group[j]].insert(group[i]), ginput[group[i]]++;
                    }
                }
                else if(isub[j].count(i)==0) { // 处理group内部排序
                    isub[j].insert(i), iinput[i]++;
                }
            }
        }
        group_ids = sort(gsub, ginput, group_ids);
        if(group_ids.empty()) return {};
        vector<int> res;
        for(int group_id : group_ids) {
            auto arr = sort(isub, iinput, groups[group_id]);
            if(arr.empty()) return {};
            res.insert(res.end(), arr.begin(), arr.end());
        }
        return res;
    }
    vector<int> sort(map<int, unordered_set<int>>& sub, map<int, int>& input, vector<int>& arr) {
        queue<int> q;
        for(int i: arr) {
            if(input[i]==0) q.push(i);
        }
        vector<int> res;
        while(!q.empty()) {
            int i=q.front(); q.pop();
            res.push_back(i);
            for(int j: sub[i]) {
                if(--input[j]==0) q.push(j);
            }
        }
        if(res.size() != arr.size()) return {};
        return res;
    }
};
```
