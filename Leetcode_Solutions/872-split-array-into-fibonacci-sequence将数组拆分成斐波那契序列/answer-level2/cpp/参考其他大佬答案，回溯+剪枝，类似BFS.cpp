### 解题思路
此处撰写解题思路

### 代码

```cpp
#include <limits>
class Solution {
public:
    // BFS
    vector<int> splitIntoFibonacci(string S) {
        try {
            str_ = S;
            vector<int> res;
            getAllSeries(0, res);
            return res;
        } catch (...) {
            return {};
        }
    }

    bool getAllSeries(int pos, vector<int>& res)
    {
        if (pos == str_.length() && res.size() > 2) {
            // 字符串遍历到末位并且有找到结果，递归结束
            return true;
        }

        for (int i = pos; i < str_.length(); ++i) {
            // 循环取0 - i + 1 - pos位置的字符串进行递归处理
            // 比如 123456579，取1, 12, 123, ..., 2, 23, 234, ... ,  3, 34, ...
            std::string sub_str_value = str_.substr(pos, i + 1 - pos);
            long long int_sub_value = std::stoll(sub_str_value);
            // 剪枝--排除超出32位整数范围的，排除首位为0且长度大于1的
            if (int_sub_value > (numeric_limits<int32_t>::max)()
                || (sub_str_value[0] == '0' && sub_str_value.length() >= 2)) {
                break;
            }

            // 判断输入数组是否是符合fibnacci规律的序列
            // 或数组个数小于2个的时候也返回正确
            if (isFibnacci(res, int_sub_value)) {
                // 将符合条件的int_sub_value推入数组
                res.push_back(int_sub_value);

                // 字符串指针往后移动，继续递归
                // 如果字符串遍历到末位并且有找到结果，递归结束
                if (getAllSeries(i + 1, res)) {
                    return true;
                }
                // 否则恢复环境继续下一种字符串序列递归
                res.pop_back();
            }
        }
        return false;
    }

    // 判断输入数组是否是符合fibnacci规律的序列或数组个数小于2个的时候也返回正确
    bool isFibnacci(const vector<int> temp, long long num)
    {
        if (temp.size() < 2) {
            return true;
        }
        return (num == uint32_t(temp.at(temp.size() - 2)) + temp.at(temp.size() - 1));
    }
private:
    std::string str_;
};
```