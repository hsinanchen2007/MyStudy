### 双指针回溯 ###
#### 思路 ####
- 将`tmp`初始化为长度为`n`的字符串（Python 中初始化为列表），`left`和`right`分别指向其左右两端
- 遍历`left`和`right`所指向字符的各种情况，对于每种情况，将两指针向中间移动，向更深一层搜索
- 当`left > right`时，说明找到了一个符合要求的数字，将其加入结果数组，递归返回
#### 代码 ####
```cpp []
class Solution {
public:
    vector<string> res;
    vector<pair<char, char>> m{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    vector<string> findStrobogrammatic(int n) {
        string tmp(n, '0');
        helper(tmp, 0, n - 1);
        return res;
    }
    void helper(string& tmp, int&& left, int&& right) {
        if (left > right) {
            res.emplace_back(tmp);
            return;
        }
        if (left == right) {
            for (auto &&c : {'0', '1', '8'}) {
                tmp[left] = c;
                res.emplace_back(tmp);
            }
            return;
        }
        for (auto &&[k, v] : m) {
            if (!left && k == '0') continue; // 排除最高位为 0 的情况
            tmp[left] = k;
            tmp[right] = v;
            helper(tmp, left + 1, right - 1);
        }
    }
};
```
```python []
class Solution(object):
    def findStrobogrammatic(self, n):
        res = []
        m = {'0': '0', '1': '1', '6': '9', '8': '8', '9': '6'}
        def helper(left, right, tmp = [None] * n): # tmp 是可变对象，只会被初始化一次
            if left > right:
                res.append("".join(tmp))
                return
            for k, v in m.items():
                if not left and right and k == '0' or left == right and k != v: continue
                tmp[left], tmp[right] = k, v
                helper(left + 1, right - 1)
        helper(0, n - 1)
        return res
```
```python3 []
class Solution:
    def findStrobogrammatic(self, n: int) -> List[str]:
        def helper(left, right, tmp = [None] * n, res = tuple()):
            if left > right: return ("".join(tmp),)
            for k, v in (('0', '0'), ('1', '1'), ('6', '9'), ('8', '8'), ('9', '6')):
                if not left and right and k == '0' or left == right and k != v: continue
                tmp[left], tmp[right] = k, v
                res += helper(left + 1, right - 1)
            return res
        return helper(0, n - 1)
```
