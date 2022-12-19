## 贪心
```c++
int cnt[4], id[4];
inline bool cmp(int a, int b) {
    return cnt[a] > cnt[b];
}
inline char itoc(int a) {
    return 'a' + (a - 1);
}
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        cnt[1] = a; cnt[2] = b; cnt[3] = c;
        id[1] = 1; id[2] = 2; id[3] = 3;
        vector<int> temp;
        temp.push_back(0);
        while (1) {
            sort(id + 1, id + 4, cmp);
            bool flag = false;
            for (int i = 1; i <= 3; ++i) {
                if (cnt[id[i]] > 0 && id[i] != temp.back()) {
                    temp.push_back(id[i]);
                    --cnt[id[i]];
                    flag = true;
                    break;
                }
            }
            if (!flag) break;
        }
        string ans = "";
        for (int i = 1; i < temp.size(); ++i) {
            ans = ans + itoc(temp[i]);
            if (cnt[temp[i]] > 0) {
                ans = ans + itoc(temp[i]);
                --cnt[temp[i]];
            }
        }
        return ans;
    }
};
```