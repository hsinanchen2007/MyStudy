class Solution {
public:
    string convert(string s, int numRows) {
        string ret;
        int len = s.size();
        int i,idx;
        if (numRows <= 1 || len <=1) {
            return s;
        }
        int blockS = (numRows - 2) * 2 + 2;
        int blockN = len / blockS;
        if (len % blockS > 0) {
            blockN = blockN + 1;
        }
        for (int j = 0; j < numRows; j++) {
            for (i = 0; i < blockN; i++) {
                idx = i * blockS + j;
                if (idx < len) ret.append(&s[idx], 1);
                if (j > 0 && j < numRows -1) {
                    idx = i * blockS + blockS - j;
                    if (idx < len) ret.append(&s[idx], 1);
                }
            }
        }
        return ret;
    }
};