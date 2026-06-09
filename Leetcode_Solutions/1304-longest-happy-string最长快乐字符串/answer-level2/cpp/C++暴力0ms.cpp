```cpp
class Solution {
public:
    string ret = "";
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> v;
        v.push_back(make_pair(a, 'a'));
        v.push_back(make_pair(b, 'b'));
        v.push_back(make_pair(c, 'c'));
        sort(v.begin(), v.end());
        string s;
        while (v[2].first >= 2 && v[1].first + v[0].first > 0) {
            if (v[2].first > v[1].first + v[0].first)
                for (int i = 0; i < 2; i++) {
                    s.push_back(v[2].second);
                    v[2].first--;
                }
            else {
                s.push_back(v[2].second);
                    v[2].first--;
            }
            if (v[1].first > v[0].first) {
                s.push_back(v[1].second);
                v[1].first--;
            } else {
                s.push_back(v[0].second);
                v[0].first--;
            }
        }
        if (v[2].first > 0)
            s.push_back(v[2].second);
        if (v[2].first > 1)
            s.push_back(v[2].second);
        while (v[1].first + v[0].first > 0) {
            if (v[1].first > v[0].first) {
                s.push_back(v[1].second);
                v[1].first--;
            } else {
                s.push_back(v[0].second);
                v[0].first--;
            }
        }
        return s;
        
        
    }
};
```
