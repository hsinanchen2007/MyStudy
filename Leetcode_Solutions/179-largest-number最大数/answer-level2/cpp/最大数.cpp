### 解题思路
如何排序
如果 ab > ba, 那么 a > b，sort自定义排序规则

### 代码

```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> m_VecNums(n, "");
        for(int i = 0; i < nums.size(); ++i) {
            m_VecNums[i] = to_string(nums[i]);
        }
        string res = "";
        sort(m_VecNums.begin(), m_VecNums.end(), CompareString);
        for(int i = 0; i < n; ++i) {
            res = res + m_VecNums[i];
        }
        int len = res.size();
        int index = 0;
        while(index < len && res[index] == '0') {
            ++index;
        }
        if (index == len) {
            return "0";
        }
        return res.substr(0);
    }

    static bool CompareString(string a, string b) {
        return ( a+b > b+a) ? true: false;
    }
};
```