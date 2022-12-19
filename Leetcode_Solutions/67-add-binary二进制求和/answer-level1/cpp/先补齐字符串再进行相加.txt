### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/656f6bed7c189149501ba7afbd5126ffe969a7445144734152963c403029cc98-image.png)

### 代码

```cpp
// 解题思想 先补齐字符串再逐个比较
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b)
    {
        string stra, strb;
        // 补齐
        if (a.length() > b.length())
        {
            stra = a;
            string strstr(a.length() - b.length(), '0');
            strb = strstr + b;
        }
        else if (a.length() < b.length())
        {
            strb = b;
            string strstr(b.length() - a.length(), '0');
            stra = strstr + a;
        }
        else if (a.length() == b.length())
        {
            stra = a;
            strb = b;
        }

        // 补齐结束 a.length()==b.length()
        string str;// 返回串
        char c = '0';// 记录 1 + 1 进位的标识
        while (!stra.empty())// 填充次数
        {
            // 逐个判断情况
            if (stra.back() == '1' && strb.back() == '1')
            {
                // 结果压入结果串中
                if (c == '0')
                {
                    str += '0';
                    c = '1';
                }
                else if (c == '1')
                {
                    str += '1';
                    c = '1';
                }
            }
            else if (stra.back() == '1' || strb.back() == '1')
            {
                // 结果压入结果串中
                if (c == '0')
                {
                    str += '1';
                    c = '0';
                }
                else if (c == '1')
                {
                    str += '0';
                    c = '1';
                }
            }
            else if (stra.back() == '0' && strb.back() == '0')
            {
                // 结果压入结果串中
                if (c == '0')
                {
                    str += '0';
                    c = '0';
                }
                else if (c == '1')
                {
                    str += '1';
                    c = '0';
                }
            }

            // 一次比较完成弹出
            stra.pop_back();
            strb.pop_back();
        }
        // 判断结束后 最后一次相加是否进位
        if (c == '1')
            str += '1';
        // 翻转得到结果
        std::reverse(str.begin(), str.end());
        return str;

    }
};
```