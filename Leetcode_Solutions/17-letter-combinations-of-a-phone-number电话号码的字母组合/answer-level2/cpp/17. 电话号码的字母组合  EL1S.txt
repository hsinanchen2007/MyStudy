每一个数字对应了几个字母，把数字串转化为字母串，其实就是要去枚举
![image.png](https://pic.leetcode-cn.com/ee3b7394b4b7f9f6e70d4c74ce214f688bef8a6b09c95cfea064007366b12cd2-image.png)
 
可以直接使用循环按照一个数字一个数字，去枚举字母，还可以利用dfs来枚举
这里我使用map<int, string>来存储，其实也可以使用其他数据结构来存储，例如
map<int, vector<char>>, map<char,string>, map<char, vector<char>>, vector<string> 使用vector的时候能够使用下标来标识

第一种：循环
```
class Solution {
    vector<string> res;
    string _digits;
    unordered_map<int,string> mp;

public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return vector<string>();
        _digits = digits;
        int idx = 0;
        mp.insert({0,"abc"});
        mp.insert({1,"def"});
        mp.insert({2,"ghi"});
        mp.insert({3,"jkl"});
        mp.insert({4,"mno"});
        mp.insert({5,"pqrs"});
        mp.insert({6,"tuv"});
        mp.insert({7,"wxyz"});
        vector<string> v1, v2;
        v1.push_back("");
        for(int i = 0; i < digits.size(); i++)
        {
            for(auto x: v1)
            {
                for(auto y: mp[digits[i] - '0' - 2])
                {
                    string s = x+y;
                    v2.push_back(s);
                }
            }
            v1 = v2;
            v2.clear();
        }
        return v1;
    }
};
```

第二种： dfs
```
class Solution {
    vector<string> res;
    string _digits;
    unordered_map<int,string> mp;


    void dfs(int idx, string s)
    {
        if(idx == _digits.size()) 
        {
            res.push_back(s);
            return;
        }
        for(auto x: mp[_digits[idx] - '0' - 2])
        {
            string ns = s + x;
            dfs(idx+1, ns);
        }


        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return vector<string>();
        _digits = digits;
        int idx = 0;
        mp.insert({0,"abc"});
        mp.insert({1,"def"});
        mp.insert({2,"ghi"});
        mp.insert({3,"jkl"});
        mp.insert({4,"mno"});
        mp.insert({5,"pqrs"});
        mp.insert({6,"tuv"});
        mp.insert({7,"wxyz"});
        string s = "";
        dfs(idx, s);
        return res;
    }
};
```

