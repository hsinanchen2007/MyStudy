### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for(auto x : nums)
        strs.push_back(to_string(x));
        sort(strs.begin(),strs.end(),cmp);
        string res = "";
        for(auto c : strs)
        res += c;
        return res;

    }
//此处需要设置为静态函数
   static bool cmp(const string& a,const string& b){
        return a + b < b + a;
    }
};
```