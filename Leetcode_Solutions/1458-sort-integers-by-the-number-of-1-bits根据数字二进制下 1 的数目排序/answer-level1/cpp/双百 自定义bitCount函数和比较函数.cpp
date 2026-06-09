### 解题思路
![image.png](https://pic.leetcode-cn.com/97750d34cec7e4d195f27b2685939d8c08b5acc0fe53a15429ae795820028ed3-image.png)


### 代码

```cpp
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr)
    {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
    static bool cmp(int a, int b) //自定义比较函数放类里时要声明成静态
    {
        int bca = bitCount(a), bcb = bitCount(b);
        return (bca == bcb) ? a < b : bca < bcb;
    }
    static int bitCount(int n) //也要静态
    {
        int cnt = 0;
        while (n > 0)
        {
            if (n & 1)
                cnt++;
            n >>= 1;
        }
        return cnt;
    }
};
```