没什么算法，大家看一下应该都懂了。。


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (!size) {
            return "";
        }
        int res = strs[0].size();
        
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < res; j++) {
                if (strs[0][j] != strs[i][j]) {
                    res = j;
                    break;
                }
            }
        }

        return strs[0].substr(0, res);
        
    }
};