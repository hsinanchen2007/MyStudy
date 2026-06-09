### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s;
        sort(nums.begin(),nums.end(),[](const int &a,const int &b){
            string s1=to_string(a)+to_string(b);
            string s2=to_string(b)+to_string(a);
            return s1>s2;});
        for(int i=0;i<nums.size();i++)
        {
            s+=to_string(nums[i]);
        }
        if(s[0]=='0') s='0';
        return s;
    }
};

```