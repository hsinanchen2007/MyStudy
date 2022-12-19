![13.mp4](f4e982b7-bcc7-4f45-beb0-4ebbe358429f)

<![1.jpg](https://pic.leetcode-cn.com/84ac7d0b51a61febbff72616580dd2f6bc19c06bcd05806c7db83d1e700b7940-1.jpg),![2.jpg](https://pic.leetcode-cn.com/3249c8330a8d11e688ec205d38093968da9b94e1973d5a76f7212a329fc5decb-2.jpg),![3.jpg](https://pic.leetcode-cn.com/dba7711dccdc3138b6549bfe85083d68cd167838526f345be8208696ffb618bb-3.jpg),![1.jpg](https://pic.leetcode-cn.com/96a88684e6cca75eabcc4de7aa869b94a42d4520b610ce8da73e57d0e4450f6e-1.jpg),![2.jpg](https://pic.leetcode-cn.com/0e1fbece5651c37553a51a115592c1e32fdcf56ca6d3f937b8f1f1d5e39b524a-2.jpg),![3.jpg](https://pic.leetcode-cn.com/c0b64d5c3612d538d0eb5012c32feaeb114434f43f9a56b746cd06cfb5544203-3.jpg),![4.jpg](https://pic.leetcode-cn.com/1f55812ff824a435557d913b8376341e76c48677b6469aefa6779a6e00e16a3f-4.jpg),![5.jpg](https://pic.leetcode-cn.com/865e46dc2c2aa5920f528453bd7b539d047987e3013f25391307a1b47e63d249-5.jpg),![6.jpg](https://pic.leetcode-cn.com/f56df31848ddff936a2283478e273287f31a69a642ccbfa53b84986f19b81d58-6.jpg),![7.jpg](https://pic.leetcode-cn.com/e2970f6e55c0da336427afa0f34d2f9ec6fd821b24027916896e1b92862fea45-7.jpg),![8.jpg](https://pic.leetcode-cn.com/5b2fcb5a1030425814ab60f6163535957422b4bf60624f44f5e2b9342cf87ec0-8.jpg)>

```cpp [-C++]
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int result = 0;
        unordered_map<string, int> store = {{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}};
        int sSize = int(s.size());
        for (int i = 0; i < sSize; i++)
        {
            if (i + 1 < sSize && store.find(s.substr(i, 2)) != store.end())
            {
                result += store[s.substr(i, 2)];
                //注意这里用到了大小为2的字符串
                i++;
            }
            else
            {
                result += store[s.substr(i, 1)];
            }
        }
        return result;
    }
};
```

![结局.jpg](https://pic.leetcode-cn.com/f369096e01c8384e1a2fd57942c94551776d2a3c9d6c676bc35a6ee6ed53d1a0-%E7%BB%93%E5%B1%80.jpg)
更多内容可以看我制作的视频
https://www.bilibili.com/video/av75776913
