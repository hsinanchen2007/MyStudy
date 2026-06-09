    
    看到题目提示所有输入都为字母，想到用字符输出映射。水平扫描字符串数组内每个字符串固定位置。每个字符出现次数应该等于 其所在字符串 在 字符串数组 里的索引。

    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int c_map[128] = {-1};
        for (int& x: c_map) x=-1;//将c_map置为-1.
        int j = 0;
        while(strs.size() > 0){
            for (int i = 0; i < strs.size(); ++i){
                if (j >= strs[i].size() ) return res;
                if (((++c_map[strs[i][j]])%strs.size()) != i) return res;
            }
            res.push_back(strs[0][j]);
            ++j;
        }
        return res;

    }
