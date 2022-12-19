```
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans;
        vector<int> cpy(arr);
        unordered_map<int, int> index_map;
        sort(cpy.begin(), cpy.end());
        int count = 0;
        int last = -1;
        for(int i = 0; i < cpy.size(); ++i) {
            if (cpy[i] != last) {
                count++;
            }
            index_map[cpy[i]] = count;
            last = cpy[i];
        }
        for(int i: arr) {
            ans.push_back(index_map[i]);
        }
        return ans;
    }
};
```
