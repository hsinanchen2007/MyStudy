```
class Solution {
public:
    bool hashTable[10001] = {false};
    int P[10010], pre[10010];
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> a;
        generateP(a, 1, n);
        return a;
    }

    void generateP(vector<vector<string> > &a, int index, int n) {
        if (index == n+1) {
            vector<string> str;
            for (int i = 1; i <= n; i++) {
                int cur_col = pre[i];
                string conc = "";
                for (int j = 1; j <= n; j++) {
                    if (cur_col == j) {
                        conc += "Q";
                    } else {
                        conc += ".";
                    }
                }
                str.push_back(conc);
            }
            a.push_back(str);
            return;
        };
        for (int x = 1; x <= n; x++) {
            if (hashTable[x] == false) {
                bool flag = true;
                for (int pre = 1; pre < index; pre++) {
                    if(abs(index - pre) == abs(x - P[pre])) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    P[index] = x;
                    pre[x] = index;
                    hashTable[x] = true;
                    generateP(a, index + 1, n);
                    hashTable[x] = false;
                }
            }
        }
    }
};
```
