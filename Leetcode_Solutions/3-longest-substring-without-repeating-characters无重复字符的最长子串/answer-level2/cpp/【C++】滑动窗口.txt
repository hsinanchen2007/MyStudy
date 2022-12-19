### 解题思路
解题思路参考了**官方题解的“方法三”**，这里给出C++的版本。

设立一个*getThePosOfSame*成员函数用于返回，在 字符串s 的 子串[left,right) 之间，与 字符target 相同的字符的下标，如果未找到相同的字符串（target与字串都不同），则返回-1。

然后在*lengthOfLongestSubstring*应用滑动窗口的方法，取子串[i,j)中与字符s[j]对应的下标。

如果为-1，说明没有，则j++右扩大。

如果不为-1，说明有，则i = pos + 1直接移动到pos右边。（因为pos和pos左边的都不行了）

关于max_len的计算则放到(pos != -1)的时候，和while循环结束的时候（处理 s.length()<=1 的情况）

### 代码

```cpp
class Solution
{
public:
    // 在左闭右开[left,right)的字符串s中，找字符target对应的下标位置，若未找到，则返回-1
    int getThePosOfSame(int left, int right, const string& s, char target) const
    {
        for (int i = left; i < right; i++)
        {
            if (s[i] == target)
            {
                return i;
            }
        }

        return -1;
    }

    int lengthOfLongestSubstring(string s)
    {
        const int len = s.length();

        int max_len = 0;
        int i = 0;
        int j = 0;

        while (j < len)
        {
            int pos = getThePosOfSame(i, j, s, s[j]);

            if (pos == -1)
            {
                j++;
            }
            else
            {
                max_len = (j - i) > max_len ? (j - i) : max_len;

                i = pos + 1;
            }
        }

        max_len = (j - i) > max_len ? (j - i) : max_len;

        return max_len;
    }
};
```