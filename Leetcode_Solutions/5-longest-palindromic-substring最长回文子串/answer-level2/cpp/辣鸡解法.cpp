### 解题思路
考虑到例如 串abcba的寻找
对于第一个字符a, 执行向右衍生 得到 ab        左右衍生 得到 
对于第二个字符b, 执行向右衍生 得到 bc abcb   左右衍生 得到 abc 
对于第三个字符c, 执行向右衍生 得到 cb bcba   左右衍生 得到 bcb abcba
...
在衍生的同时比较是否是回文串,保存最大的回文串...
最后一个字符无法向右衍生和左右衍生,故主循环是0-length-1

向右衍生: 选定当前基准字符索引 L 和基准字符的右边的索引 R ,下一个循环遍历两边索引 L-- R++
左右衍生: 选定当前基准字符的左边的索引 L 和基准字符的右边的索引 R 下一个循环遍历两边索引 L-- R++

执行用时 :
48 ms
, 在所有 C++ 提交中击败了
69.57%
的用户
内存消耗 :
64.8 MB
, 在所有 C++ 提交中击败了
37.28%
的用户

**辣鸡辣鸡,辣鸡解法,大家贱笑贱笑**

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0)
        {
            return "";
        }

        string maxHuiwen = s.substr(0, 1);
        for (int i = 0; i<s.length()-1; i++)
        {
            string str = checkHuiWen(s, i);
            if (str.length()>maxHuiwen.length())
            {
                maxHuiwen = str;
            }
        }
        return maxHuiwen;
    }
    string checkHuiWen(string s,int index)
    {
        int maxLenth2 = 1;
        int maxLenth3 = 1;
        string maxHuiwen;

        //向右衍生
        int left2 = index;
        int right2 = index+1;
        int length2 = 0;
        int L2 = 0;
        int R2 = 0;
        while (left2 >= 0 && right2 < s.length() && s[left2] == s[right2])
        {
            length2+=2;
            if (length2 > maxLenth2)
            {
                maxLenth2 = length2;
                L2 = left2;
                R2 = right2;
            }
            left2--;
            right2++;
        }

        //左右衍生
        int left3 = index - 1;
        int right3 = index + 1;
        int length3 = 1;
        int L3 = 0;
        int R3 = 0;
        while (left3 >= 0 && right3 < s.length() && s[left3] == s[right3])
        {
            length3+=2;
            if (length3 > maxLenth3)
            {
                maxLenth3 = length3;
                L3 = left3;
                R3 = right3;
            }
            left3--;
            right3++;
        }

        if (length2 > length3)
        {
            maxHuiwen = s.substr(L2, R2 - L2 + 1);
        }
        else
        {
            maxHuiwen = s.substr(L3, R3 - L3 + 1);
        }

        
        return maxHuiwen;
    }
};
```
