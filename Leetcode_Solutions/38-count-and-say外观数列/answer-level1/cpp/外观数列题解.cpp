### 解题思路
此处撰写解题思路
设置初始序列，初始值为“1”
然后按照所给参数和规则“读”
用“读”出来的序列更新原序列
重复“读”的操作直至到达n
返回结果序列
### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string result = "1";            // 结果，初始为1
        string tmp;                     // 中间序列
        auto t_it = result.begin();     // 记忆字符
        int icount;                     // 计数器
        for(int i = 0; i < n - 1; ++i)  // 控制循环到第几项
        {
            tmp = "";                   // 重置中间序列
            for(auto it = result.begin(); it != result.end(); ++it) // 遍历序列
            {
               t_it = it;               // 保存当前字符
                icount = 1;             // 重置计数器
                while(*it == *(it + 1)) // 计算当前字符的连续重复次数
                {
                    ++icount;
                    ++it;
                }
                tmp += '0' + icount;    // 按照数量“读”出来
                tmp += *t_it;           // 将保存的字符“读”出来
            }
            result = tmp;               // 更新结果序列
        }
        return result;                  // 返回结果
    }
};
```