C++ 版本的代码，具体参考相关链接

## 回溯法

- [参考](https://leetcode-cn.com/problems/gray-code/solution/jian-dan-de-si-lu-44ms-by-dannnn/)

```cpp
// 回溯法
class Solution {
public:
    // 这个函数可以使用 stoi("1101", 0, 2) 计算
    int s2int(string x)
    {
        int ret = 0;
        unsigned int mask = 1;
        for (auto it = x.rbegin(); it != x.rend(); it++) {
            ret += (*it - '0') * mask;
            mask <<= 1;
        }
        return ret;
    }

    // 如果当前二进制是 0 那下一个分支就是 0, 1
    // 如果当前二进制是 1 那下一个分支就是 1, 0
    void getGray(int n, int flag, string str, vector<int>& ret)
    {
        // 递归出口
        if (str.length() == n)
            // ret.push_back(stoi(str, 0, 2));  // 二进制字符串转整数
            ret.push_back(s2int(str)); // 二进制字符串转整数
        else if (flag == 0) {
            str.push_back('0');
            getGray(n, 0, str, ret);
            str.pop_back();
            str.push_back('1');
            getGray(n, 1, str, ret);
        } else {
            str.push_back('1');
            getGray(n, 0, str, ret);
            str.pop_back();
            str.push_back('0');
            getGray(n, 1, str, ret);
        }
    }

    vector<int> grayCode(int n)
    {
        vector<int> ret;
        getGray(n, 0, "", ret);
        return ret;
    }
};
```
## 递推公式

- [参考](https://leetcode-cn.com/problems/gray-code/solution/gray-code-jing-xiang-fan-she-fa-by-jyd/)

$$G(n + 1) = G(n) + map(x + x^n, G'(n))$$

```cpp
// G(n + 1) = G(n) + map(x + x^n, G'(n))
class Solution {
public:
    vector<int> grayCode(int n)
    {
        vector<int> ret = { 0 }; // 从0开始
        unsigned int mask = 1;
        for (int i = 0; i < n; i++) {
            // 在前一个格雷编码的基础上 逆序加上mask
            int m = ret.size();
            for (int j = m - 1; j >= 0; j--) {
                ret.push_back(mask + ret[j]);
            }
            // 每增加一位 mask * 2 表示在二进制前面加 1 转换为十进制即表示 + mask
            mask <<= 1;
        }
        return ret;
    }
};
```