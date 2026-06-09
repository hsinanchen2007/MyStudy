### 解题思路

1.先转化为字符串。
2.s1+s2<s2+1 表示s1小于s2。比如 "12"小于"21" ，则"1"小于"2";

```cpp
class Solution {
public:
    string minNumber(vector<int>& nums) {
        if(!nums.size()){
            return std::string();
        }
        std::vector<std::string>str_nums;
        for(const auto x:nums){
            str_nums.push_back(std::to_string(x));
        }

        std::sort(str_nums.begin(),str_nums.end(),[](const std::string& s1,const std::string& s2){return s1+s2<s2+s1;});
        std::string str;
        for(auto x:str_nums){
            str+=x;
        }

        return str;
    }
};
```