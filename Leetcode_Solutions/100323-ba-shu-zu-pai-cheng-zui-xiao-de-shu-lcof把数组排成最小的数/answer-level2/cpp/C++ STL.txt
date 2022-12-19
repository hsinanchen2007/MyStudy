### 解题思路
C++ STL

### 代码

```cpp
/* 排序类问题： 定义a > c的方法
 *
 * */
class Solution {
public:
    string minNumber(vector<int>& nums) {
        auto f = [](const string &a, const string &b){
            return a + b < b + a;
        };
        vector<string> convert;
        for(int num:nums){
            convert.push_back(to_string(num));
        }
        sort(convert.begin(), convert.end(), f);
        string ret;
        for(const string &s:convert){
            ret += s;
        }
        return ret;
    }
};
```