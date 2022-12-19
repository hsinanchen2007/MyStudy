### 解题思路


### 代码

```cpp
class Solution {
public:
    void permutation(set<string> &res, vector<bool> &flag, string &temp, string s, int expectedSize)
    {
        if(temp.size() == expectedSize)
        {
            res.insert(temp);
            return;
        }
        for(int i=0; i < s.size(); ++i)
        {
            if(flag[i] == false)
            {
                temp += s[i];
                flag[i] = true;
                permutation(res, flag, temp, s, expectedSize);
                flag[i] = false;
                temp.pop_back();  //撤回上一步操作
            }
        }
    }
    vector<string> permutation(string s) {
        if(s.size() == 0)return {};
        set<string> res;  //用set存储结果，防止abb, abb, bba, bba, aba, aba这样的重复字符串出现
        vector<bool> flag(s.size(), false);
        int expectedSize = s.size();
        for(int i=0; i < s.size(); ++i)
        {
            string temp;
            flag[i] = true;
            temp += s[i];
            permutation(res, flag, temp, s, expectedSize);
            flag[i] = false;  //撤回上一步操作
        }
        return vector<string>(res.begin(), res.end());  //返回vector
    }
};
```