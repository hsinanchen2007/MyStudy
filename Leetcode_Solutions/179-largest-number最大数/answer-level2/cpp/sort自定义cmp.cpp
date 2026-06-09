### 解题思路
1.如果你用的C++，你会发现默认的函数的返回值是string而不是int类型。
2.你需要知道我们可以借助于to_string函数将int转换成一个string
3.而最终返回的最大数就是一个由多个从大到小string组成的新的string
4.sort将字符串从大到小排序，我们自定义cmp函数即可，输入时两个int，返回时大的string。

### 代码

```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res = "";

        sort(nums.begin(), nums.end(), cmp);
        
        for(int i=0;i<nums.size();i++)
        {
            res += to_string(nums[i]);
        }

        if(res[0] == '0') 
        {
            return "0";
        } 
        else 
        {
            return res;
        }
    }

    bool static cmp(int a, int b) 
    {
        string s1 = to_string(a);
        string s2 = to_string(b);
        return s1 + s2 > s2 + s1;
    }
};
```