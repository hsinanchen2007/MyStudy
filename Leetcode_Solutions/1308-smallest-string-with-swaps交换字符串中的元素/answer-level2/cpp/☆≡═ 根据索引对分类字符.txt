根据可以交换的索引对，使用并查集分类字符，然后对同类字符排序，写回原字符串。
```
int v[100001];
int find (int i) {
    while (i != v[i]) {
        v[i] = v[v[i]];
        i = v[i];
    }
    return i;
};
class Solution {
public:
    string smallestStringWithSwaps(string s, const vector<vector<int>>& pairs) {
        const int n = s.size();
        for (int i = 0; i < n; i++)
            v[i] = i;
        for (const auto& p : pairs) {
            v[find(p[0])] = find(p[1]);
        }
        
        unordered_map<int, vector<char>>classification;
        
        for (int i = n - 1; 0 <= i; -- i) {
            const int t = find(i);
            v[i] = t;
            if (!classification.count(t)) classification[t] = vector<char>();
            classification[t].push_back(s[i]);
        }

        for (auto& cla : classification) {
            vector<char>& vec = cla.second;
            sort(vec.rbegin(), vec.rend());
        }
        
        for (int i = 0; i < n; i++) {
            const int t = v[i];
            s[i] = classification[t].back();
            classification[t].pop_back();
        }
        return s;
    }
};
```
