排序，考虑数组所有为0的情况

### 代码

```cpp
class Solution {
public:
    bool static cmp(int a,int b)
    {
        string s1 = to_string(a);
        string s2 = to_string(b);
        if(s1 + s2 > s2 + s1)
        return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(),nums.end(),cmp);
        int flag = 0;
        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i] != 0)
            {
                flag = 1;
                break;
            }

        }
        if(!flag)
        return "0";
        for(int i = 0;i < nums.size();i++)
        ans += to_string(nums[i]);
        return ans;
    }
};
```