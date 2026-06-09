```
typedef pair<int, char> pic;
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ret;
        vector<pic> cnts{pic(a, 'a'), pic(b, 'b'), pic(c, 'c')};
        int cur = 0;
        while(true) {
            sort(cnts.begin(), cnts.end(), [](pic &a, pic &b) {
                return a.first > b.first;
            });
            if (cnts[0].first == 0) {
                break;
            }
            if (ret.size() == 0 || (cnts[0].second == ret.back() && cur < 2)) {
                cur++;
                ret += cnts[0].second;
                cnts[0].first--;
            }
            else if(cnts[0].second != ret.back()) {
                cur = 1;
                ret += cnts[0].second;
                cnts[0].first--;
            }
            else if (cur == 2) {
                if (cnts[1].first == 0) {
                    break;
                }
                cur = 1;
                ret += cnts[1].second;
                cnts[1].first--;
            }
        }
        return ret;
    }
};
```
