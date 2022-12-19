### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    static bool compare(const string &s1, const string &s2)
    {
        return (s1+s2) < (s2+s1);  //自定义的比较函数
    }
    string minNumber(vector<int>& nums) {
        if(nums.size() == 0)return " ";
        vector<string> svec;
        for(auto c : nums)
        {
            svec.push_back(to_string(c));  //to_string将数字转换成字符串
        }
        sort(svec.begin(), svec.end(), compare);
        string res;
        for(auto str : svec)
        {
            res += str;
        }
        return res;
    }
};
```