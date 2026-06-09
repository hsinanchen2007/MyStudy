```
class Solution {
public:
    const int N = 26;
    vector<vector<string> > P;
    Solution() {
        P = vector<vector<string> >(N, vector<string>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int ri = i / 5;
                int ci = i % 5;
                int rj = j / 5;
                int cj = j % 5;
                int dr = rj - ri;
                int dc = cj - ci;
                string hor, ver, s;
                if (dc > 0) hor.append(dc, 'R');
                else if (dc < 0) hor.append(-dc, 'L');
                if (dr > 0) ver.append(dr, 'D');
                else if (dr < 0) ver.append(-dr, 'U');
                if (j > i) s = hor + ver;
                else s = ver + hor;
                P[i][j] = s;
            }
        }
    }
    string alphabetBoardPath(string target) {
        string res;
        int c0 = 'a';
        for (auto c : target) {
            res += P[c0 - 'a'][c - 'a'];
            res += '!';
            c0 = c;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/83822c78267d62e81dc513e9fef00905fe97c16c5f8e773daa5bf7e6214a5212-image.png)
