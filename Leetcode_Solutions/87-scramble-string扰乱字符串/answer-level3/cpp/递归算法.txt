### 解题思路：递归
由于无法得知原字符串分割的位置，所以通过蛮力遍历每一个位置对原字符串进行分割，然后比较原字符串和扰乱字符串分割之后的子串是否相等。子串同样进行了分割，则需要再对子串进行分割判断。这个时候就可以使用递归了。

由于分割之后还可能进行交换，所以需要判断两种情况：
1. 直接对原字符串进行分割，比较原字符串和扰乱字符串分割之后的子串是否相等。即s1[0, i] == s2[0, i] && s1[i+1, len - 1] == s2[i+1, len -1]。
2. 将分割后的两个子串交换，然后比较交换后的子串。s1[0, i] == s2[len-1 - i, len-1] && s1[i+1, len - 1] == s2[0, len-i]。

优化：
由于分割交换并不会改变字符串中字符的个数，所以可以通过统计并比较两字符串中各字符的个数是否相等做一次筛选。
如果不等，则一定不是扰乱字符串。这是一个 __必要条件__。

### 代码

```cpp
class Solution
{
public:
        bool isScramble(string s1, string s2)
        {
                if (s1.size() <= 1)
                {
                        if (s1 == s2)
                        {
                                return true;
                        }
                }
                else
                {
                        return _isScramble(s1, s2);
                }

                return false;
        }

        bool _isScramble(string s1, string s2)
        {                       
                int m = s1.length();
                if(s1 == s2)
                {
                        return true;
                }

                //统计s1和s2的字符个数，判断相应的字符个数是否相等。（必要条件）
                int char_num[26] = {0};
                for(int i=0; i<m;i++)
                {
                        char_num[s1[i] - 'a']++;
                        char_num[s2[i] - 'a']--;
                }

                for(int i=0; i<26; i++)
                {
                        if(char_num[i] != 0)
                        {
                                return false;
                        }
                }

                for (int i = 0; i < m-1; i++)
                {
                        //蛮力切割
                        if ((_isScramble(s1.substr(0, i+1), s2.substr(0, i+1)) &&
                        _isScramble(s1.substr(i + 1, m - (i + 1)), s2.substr(i + 1, m - (i + 1)))) == 1)
                        {
                                return true;
                        }

                        //切割并且交换
                        if ((_isScramble(s1.substr(0, i+1), s2.substr(m-(i+1), i+1)) &&
                        _isScramble(s1.substr(i + 1, m - (i + 1)), s2.substr(0, m - (i + 1)))) == 1)
                        {
                                return true;
                        }
                }
                return false;
        }
};

```