### 解题思路
1.两次字符串拆分：第一次拆空格，第二次拆'('
2.用hash保存内容，当内容对应的路径大于2时，输出

### 代码

```cpp
class Solution {
public:
    stringstream sstream;
    void splictstr(string input, char splict,vector<string>& strvec)
    {
        sstream.clear();
        sstream << input;
        string str;
        while (getline(sstream, str, splict)) {
            strvec.push_back(str);
        }
        return ;
    }

    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        unordered_map<string, vector<string>> pathmap;
        vector<vector<string>> result;
        for (auto path : paths) {
            vector<string> strvec;
            splictstr(path, ' ',strvec);
            string strfirst = strvec[0];
            for (int i = 1; i < strvec.size(); i++) {
                vector<string> secstrvec;
                splictstr(strvec[i], '(',secstrvec);
                secstrvec[1].pop_back();
                pathmap[secstrvec[1]].push_back(strfirst + "/" + secstrvec[0]);
            }
        }

        for (auto path : pathmap) {
            if(path.second.size()>1){
                result.push_back(path.second);
            }
        }

        return result;
    }
};
```