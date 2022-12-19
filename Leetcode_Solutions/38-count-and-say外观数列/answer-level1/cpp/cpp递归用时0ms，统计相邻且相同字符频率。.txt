### 解题思路
解读题目：
    **输入为n的结果是对输入n-1结果中相邻且相同字符频率的统计**
比如n=5时返回的string = "111221"，里面包含3个相邻的1，2个相邻的2，1个单独的1，那么n=6时，返回的结果为string="312211"。
    由于当前的输出来源于上一次运算的输出，很容易想到可以用递归来组织代码。在当前函数调用对上一次函数调用的返回值进行相邻且相同字符频率统计即可。
提交记录：
![image.png](https://pic.leetcode-cn.com/94d21668391f03c8c7f2919e7c225c5b5115f96377df767554759baf6ce0348b-image.png)

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)//递归基
        {
            return "1";
        }
        string check_frq = countAndSay(n - 1);
        string result;
        int frequency = 1;
        for(int i = 1; i < check_frq.size(); i++)
        {
            if(check_frq[i] == check_frq[i - 1])//相邻且相同的字符
            {
                frequency++;
            }
            else
            {
                result += frequency + '0';//遇到新的字符区域，将之前的统计结果存入字符串
                result += check_frq[i - 1];
                frequency = 1;//initial the freq of check_frq[i - 1]
            }
        }
        result += frequency + '0';//处理字符串尾部遗留
        result += check_frq[check_frq.size() - 1];
        return result;
    }
};
```