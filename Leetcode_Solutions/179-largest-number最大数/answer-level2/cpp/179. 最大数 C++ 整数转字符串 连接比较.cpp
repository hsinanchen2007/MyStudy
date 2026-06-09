### 解题思路
请参考官方题解
https://leetcode-cn.com/problems/largest-number/solution/zui-da-shu-by-leetcode/

想法：
越大的数字在越前面越好；
1）两个字符相互比较，并不容易确定各种场景下，究竟谁放在前面最大。
2）尤其是存在842,8427；3,30这些组合，处理这些细节会异常麻烦
3）因此，我们采用两数相加，字符串比较的方式，代码编写比较简单




### 代码

```cpp
class Solution {
public:
    static bool myfun(string str1, string str2)
    {
        string strfirst = str1 + str2;
        string strsecond = str2 + str1;
        if (strfirst > strsecond) {
            return true;
        } else if (strfirst < strsecond) {
            return false;
        }

        return false;
    }

    string largestNumber(vector<int> &nums)
    {
        vector<string> strs;
        string result;
        for (auto num : nums) {
            strs.push_back(to_string(num));
        }
        sort(strs.begin(), strs.end(), myfun);

        for (auto str : strs) {
            result.append(str);
        }

        while (result.front() == '0' && result.size() > 1) {
            result.erase(result.begin());
        }

        return result;
    }
};
```