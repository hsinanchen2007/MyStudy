# ### 代码解读
# ```Python []
class Solution:
    def romanToInt(self, s: str) -> int:
        d = {'I':1, 'IV':3, 'V':5, 'IX':8, 'X':10, 'XL':30, 'L':50, 'XC':80, 'C':100, 'CD':300, 'D':500, 'CM':800, 'M':1000}
        return sum(d.get(s[max(i-1, 0):i+1], d[n]) for i, n in enumerate(s))
# ```
# ```C++ []
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> m = {{"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000}};
        int r = m[s.substr(0, 1)];
        for(int i=1; i<s.size(); ++i){
            string two = s.substr(i-1, 2);
            string one = s.substr(i, 1);
            r += m[two] ? m[two] : m[one];
        }
        return r;
    }
};
# ```

# ### 代码行数：解析
# 1. 构建一个字典记录所有罗马数字子串，注意长度为2的子串记录的值是（实际值 - 子串内左边罗马数字代表的数值）

# 2. 这样一来，遍历整个 $s$ 的时候判断当前位置和前一个位置的两个字符组成的字符串是否在字典内，如果在就记录值，不在就说明当前位置不存在小数字在前面的情况，直接记录当前位置字符对应值

# 举个例子，遍历经过 $IV$ 的时候先记录 $I$ 的对应值 $1$ 再往前移动一步记录 $IV$ 的值 $3$，加起来正好是 $IV$ 的真实值 $4$。max 函数在这里是为了防止遍历第一个字符的时候出现 $[-1:0]$ 的情况

# ### 知识拓展

# ![image.png](https://pic.leetcode-cn.com/576c1d21b07aa085382b70207b3e3a0521e1968f323b7efcb643769fd3babdfa-image.png){:width="320px"}
# {:align=center}

# 【🃏知识卡片】哈希表存储的是由键（`key`）和值（`value`）组 成的数据。例如，我们将每个人的性别作为数 据进行存储，键为人名，值为对应的性别。

#   - Python 中我们使用字典 `{key : value}` 来初始化哈希表

#   - 通过 `key` 查找 `value` 的时间复杂度为 $O(1)$

#   - 这题题解中的 `d` 就是一个字典，其中 `get(key, default)` 函数可以通过 `key` 从 `d` 中找出对应的值，如果 `key` 不存在则返回默认值 `default`