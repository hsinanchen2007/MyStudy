```c++
class Solution {
public:
    string compressString(string S) {
        string compress;
        int i = 0;
        while (i < S.length()) {
            int j = i + 1;
            while (j < S.length() && S[j] == S[i]) {
                j++;
            }
            compress += S[i];
            compress += to_string(j - i);
            i = j;
        }
        if (compress.length() < S.length()) {
            return compress;
        }
        return S;
    }
};
```