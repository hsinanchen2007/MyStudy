### 解题思路
自定义sort函数，利用2个字符串字典序比较大小

### 代码

```cpp
class Solution {
public:
    static bool myfun(string a, string b)
    {
        string newab = a + b;
        string newba = b + a;
        if (newab < newba) {
            return true;
        }

        return false;
    }
    string minNumber(vector<int> &nums)
    {
        vector<string> numstr;
        string result;

        for (auto num : nums) {
            numstr.push_back(to_string(num));
        }

        sort(numstr.begin(), numstr.end(), myfun);

        for (auto s : numstr) {
            result.append(s);
        }

        return result;
    }
};
```