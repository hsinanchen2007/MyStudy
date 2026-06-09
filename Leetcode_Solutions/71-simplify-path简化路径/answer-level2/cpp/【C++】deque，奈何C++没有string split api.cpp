```
/*
* Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
* Description: i love leetcode
* Author: Nicolas
* Create: 2019/10/09
*/
class Solution {
public:
    string simplifyPath(string path)
    {
        deque<string> realPath;
        string folder;
        for (string::const_iterator iter = path.begin();
                iter != path.end();
                ++iter) {
            if (*iter == '/') {
                appendPath(folder, realPath);
                continue;
            } else {
                folder.push_back(*iter);
            }
        }
        appendPath(folder, realPath);

        string result;
        while (!realPath.empty()) {
            result += "/";
            result += realPath.front();
            realPath.pop_front();
        }
        if (result.empty()) {
            result = '/';
        }
        return result;
    }

    void appendPath(string &folder, deque<string> &realPath)
    {
        if (!folder.empty()) {
            if (folder.compare("..") == 0) {
                if (!realPath.empty()) {
                    realPath.pop_back();
                }
            } else if (folder.compare(".") == 0) {
            } else {
                realPath.push_back(folder);
            }
            folder.clear();
        }
    }

};
```
