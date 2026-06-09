### 解题思路
确定排序规则是这题的难点
static bool cmp(string x,string y){
        string a=x+y;
        string b=y+x;
        return a<b;
    }

### 代码

```cpp
class Solution {
public:
    static bool cmp(string x,string y){
        string a=x+y;
        string b=y+x;
        return a<b;
    }
    string minNumber(vector<int>& nums) {
        string res;
        if(nums.size()==0)
            return res;
        vector<string> t;
        for(int i=0;i<nums.size();i++)
            t.push_back(to_string(nums[i]));
        sort(t.begin(),t.end(),cmp);
        for(int i=0;i<t.size();i++)
            res+=t[i];
        return res;
    }
};
```