```
int nxt[20001][130];
pair<int, int> arr[101];
int vis[101];
int v[101];
class Solution {
public:
    void get(string s, int len) {
        memset(nxt[len], -1, sizeof(nxt[len]));
        for (int i = len - 1; i >= 0; --i) {
            for (int j = 0; j < 128; ++j) 
                nxt[i][j] = nxt[i + 1][j];
            nxt[i][s[i + 1]] = i + 1;
        }
    }

    pair<int, int> getpair(string& s, int sta, int val) {
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            if (nxt[sta][s[i]] == -1) {
                return {-1, -1};
                break;
            }
            sta = nxt[sta][s[i]];
        }
        return {(sta - 1) % val + 1, ceil(1.0 * sta / val) - 1};   
    }

    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        map<char, int>ma;
        for (auto it : s1) ma[it] = 1;
        for (auto it : s2) if (!ma[it]) return 0;
        if (n1 == 0) return 0;
        memset(vis, -1, sizeof(vis));
        int len1 = s1.length();
        int len2 = s2.length();
        string ss = "";
        for (int i = 1; i <= 2 * len1 * len2; ++i) ss += s1;
        get(" " + ss, 2 * len1 * len2);
        int id = 0;
        for (int i = 0; i < len1; ++i) {
            if (s1[i] == s2[len2 - 1]) {
                arr[i + 1] = getpair(s2, i + 1, len1);
            }
        }
        arr[0] = getpair(s2, 0, len1);
        ++arr[0].second;
        int now = 0;
        int sum = 0;
        while (now <= n1) {
            if (arr[id].first == -1) break;
            if (vis[id] != -1) {
               int delta = now - vis[id];
               int nxt = ((n1 - now) / delta) * delta;
               sum += (sum - v[id]) * ((n1 - now) / delta);
               memset(vis, -1, sizeof(vis));
               now += nxt;
               continue;
            }
            vis[id] = now;
            v[id] = sum;
            now += arr[id].second;
            id = arr[id].first;
            if (now <= n1) ++sum;
        }
        return sum / n2;
    }
};
```
