```
class Solution {
public:
    char upper(char x) {
        if (x >= 'a' && x <= 'z')
            return x - 'a' + 'A';
        return x;
    }
    char lower(char x) {
        if (x >= 'A' && x <= 'Z')
            return x - 'A' + 'a';
        return x;
    }
    vector<string> letterCasePermutation(string S) {
        vector<int> char_indices;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] < '0' || S[i] > '9')
                char_indices.push_back(i);
        }
        vector<string> res;
        int N = char_indices.size();
        if (N == 0)
            return {S};
        int M = 1 << N;
        for (int i = 0; i < M; ++i) {
            string s;
            for (int j = 0; j < N; ++j) {
                int k = (j == 0) ? 0 : char_indices[j - 1] + 1;
                for (; k < char_indices[j]; ++k) {
                    s += S[k];
                }
                if (i & (1 << j)) {
                    s += upper(S[char_indices[j]]);
                } else {
                    s += lower(S[char_indices[j]]);
                }
            }
            for (int k = char_indices[N - 1] + 1; k < S.size(); ++k)
                s += S[k];
            res.push_back(s);
        }
        return res;
    }
};
```
