```c++
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> m(26, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (char c : A[i]) {
                m[c - 'a'][i]++;
            }
        }
        vector<string> r;
        int i = 0;
        for (auto& row : m) {
            int c = *min_element(row.begin(), row.end());
            while (c--) r.push_back(string(1, 'a' + i));
            i++;
        }
        return r;
    }
};
```