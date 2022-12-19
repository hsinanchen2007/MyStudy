```
bool cmp(vector<int>& a,vector<int>& b) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        if (a[i] == b[i]) continue;
        return a[i] > b[i];
    }
    return a[0] < b[0];
}
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        vector<vector<int>> mat(26,vector<int>(27,0));
        for (int i = 0; i < 26; i++) {
            mat[i][0] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < votes[i].size(); j++) {
                mat[votes[i][j] - 'A'][j + 1]++;
            }
        }
        sort(mat.begin(),mat.end(),cmp);
        string ans = "";
        for (int i = 0; i < 26; i++) {
            bool flag = false;
            for (int j = 1; j < 27; j++) {
                if (mat[i][j]) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                ans += 'A' + mat[i][0];
            }
        }
        return ans;
    }
};
```