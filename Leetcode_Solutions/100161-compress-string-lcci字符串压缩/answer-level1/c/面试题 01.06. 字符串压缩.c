### 解题思路
很简单的一次过的方式
使用到双指针
aabccccccaaa

i = 0第一次走到a
然后 j = i + 1 然后往后走 走到第一个不等于S[i]的位置
那么这一段区间内都是S[i]，只需要写入S[i] + (j - i);
但是我们要存入都是字符所以需要加上'0' 因为 '0'是48，不能直接输入j - i( 5 - 2) = 3，而3的ascll的
数值是51,所有需要加上一个'0';
但是有可能数字会超过10，而字符最多显示到9，所有需要一个数组存着数字然后一个一个写入

还有一个点就是结尾的部分需要单独处理一下。

执行用时 :
8 ms, 在所有 C++ 提交中击败了97.61%的用户
内存消耗 :
8.7 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        char str[50050];
        int index = 0;
        bool sign;
        int shengyu;

        for(int i = 0 ; i < S.length(); i++)
        {
            sign = true;
            shengyu = i;

            for(int j = i + 1 ; j < S.length(); j++)
            {
                if(S[i] != S[j])
                {
                   str[index++] = S[i];
                   int d[5];
                   int pre = 0;
                   int len = j - i;
                    while(len != 0)
                    {
                        d[pre++] = '0' + len % 10;
                        len = len / 10;
                    }

                    while(pre > 0)
                        str[index++] = d[--pre];

                    i = j - 1;
                    sign = false;
                    break;
                }
            }

            if(sign != false)
                break;

            if(index > S.length())
                return S;
        }

        if(sign)
        {
            int len = S.length() - shengyu;
            str[index++]  = S[shengyu];
            int d[5];
            int pre = 0;
            while(len != 0)
            {
                d[pre++] = '0' + len % 10;
                len = len / 10;
            }

            while(pre > 0)
                str[index++] = d[--pre];

            if(index >= S.length())
                return S;

            str[index] = '\0';
        }
        else
            str[index] = '\0';
        return str;
    }
};
```