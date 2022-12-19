### 解题思路
首先题目的意思是用下一行的数字序列描述上一行的数字序列，每两个数字是一对，前面的数字用于描述后面一个数字在上一行s之中出现了多少次。
具体思路在代码注释
### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";//首先初始化一个s字符串，初始值为1
        for(int i = 0;i < n-1;i++)//循环n-1次
        {
            string ns;
            for(int j = 0;j < s.size();j++)//for循环用于记录最长重复序列的长度
            {
                int k = j;//k从j开始
                while(k < s.size() && s[k] == s[j])
                {
                    k++;//此时k记录的是最长l序列长度
                }
                ns += to_string(k-j) + s[j];//结果记录
                j = k-1;//ji跳到k-1处，因为j下一次循环要++;
            }
            s = ns;
        }
        return s;
    }
};
```