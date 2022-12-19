### 解题思路
分治算法，逐步进行；设 low = 0, high = 2 * k - 1; 对s[low]~ s[low + k - 1] 进行字符串的反转，即reverse(s, low, low + k - 1)，然后 循环(low < s.size()) low = high + 1, high = high + 2 * k 重复以上步骤

### 代码

```cpp
class Solution {
public:
    string reverseStr(string s, int k) {
        int low = 0, high = 2 * k - 1;
        while( low < s.size())
        {
            reverse(s, low, low + k - 1);
            low = high + 1;
            high += 2 * k;
        }
        return s;
    }

    void reverse(string & s, int low, int high)
    {
        int i = low;
        int j = min((int)s.size() - 1, high);
        for(; i < j; i++, j--)
        {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
        }
    }
};
```