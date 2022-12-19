```
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        
        //
        // 方法一
        //
        
        // 遍历字符串数组,对每个字符进行比较
        // int pre_idx = 0;
        // while (1) {
        //     for (int s = 1; s < strs.size(); ++s) {
        //         if (strs[s].length() < pre_idx+1 || 
        //             strs[s][pre_idx] != strs[s-1][pre_idx]) {
        //             return string(strs[s].begin(), strs[s].begin()+pre_idx);
        //         }
        //     }
        //     pre_idx++;
        // }
        
        //
        // 方法二
        //
        // 先找出前两个的字符串的最长公共子串长度
        int pre_len = 0;
        while(pre_len < strs[0].length() &&
              pre_len < strs[1].length() &&
              strs[0][pre_len] == strs[1][pre_len]) {
            pre_len++;
        }
        
        // 遍历其他字符串,逐步收敛子串长度
        for (int s = 2; pre_len  && s < strs.size(); ++s) {
            if (strs[s].length() < pre_len)
                pre_len = strs[s].length();
            while (pre_len && strs[s][pre_len-1] != strs[0][pre_len-1]) {
                pre_len--;
            }
        }
        
        return string(strs[0].begin(), strs[0].begin()+pre_len);
    }
```
