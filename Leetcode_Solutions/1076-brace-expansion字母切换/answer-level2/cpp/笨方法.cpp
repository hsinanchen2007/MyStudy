好像和之前一道电话号码的题目相似，其实就是组合一下。。
大概就是条件判断+一些组合之类的，看大佬的解法很多，其实比赛那边也可以直接看到大佬的代码。

```
class Solution {
public:
    vector<string> permute(string S) {
        vector<string> tmp;
        vector<string> res;
        vector<string> tmp2;
        bool flag = 0;
        for (char i : S) {
            if (i == '{') {
                flag = 1;
                tmp.clear();
            }
            else if (i == '}') {
                flag = 0;
                if (res.empty()) {
                    res = tmp;
                    tmp.clear();
                } else {
                    for (string a : res) {
                        for (string b : tmp) {
                            tmp2.push_back(a + b);
                        }
                    }
                    res = tmp2;
                    tmp2.clear();
                }
            }
            else if (i != ',') {
                if (flag) tmp.push_back(string{i});
                else {
                    if (res.empty()) {
                        if (!tmp.empty()) {
                            for (string a : tmp) res.push_back(a + i);
                            tmp.clear();
                        } else {
                            res.push_back(string{i});
                        }
                    } else {
                        for (string &a : res) a += i;
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
```