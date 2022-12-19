![image.png](https://pic.leetcode-cn.com/2b436edd85c42ee8ff53217e6c6d22c86144fbe1a6fec53db252b8cf6c8024ef-image.png)

1.构造字典，所有可能的拆分
2.使用DFS回溯，终止条件为拼接的字符串长度大于等于s的长度
```
/*
* Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
* Description: 1003. 检查替换后的词是否有效
* Author: Nicolas
* Create: 2019.9.19
*/

class Solution
{
public:
    Solution ()
    {
        valid = false;
    }

    bool isValid(string S)
    {
        if (S.size() < 3) {
            return false;
        }
        isValidDfs("abc", S, words);
        return valid;
    }

private:
    void isValidDfs(string result, string s, map<string, string> const &words)
    {
        if (result.length() > s.length()) {
            return;
        }
        if (result.compare(s) == 0) {
            valid = true;
            return;
        }

        for ( map<string, string>::const_iterator iter = words.begin();
                iter != words.end();
                ++iter) {
            string newResult = iter->first + result + iter->second;
            isValidDfs(newResult, s, words);
        }
    }
private:
    bool valid;
private:
    map<string, string> words = {{"abc", ""}, {"a", "bc"}, {"ab", "c"}, {"", "abc"}, /*{"bc", "a"}, {"c", "ab"}*/};
};
```
