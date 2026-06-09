![14.mp4](a7dbc070-d0f8-46c1-8a80-b7f42a1e8f2b)

<![1.jpg](https://pic.leetcode-cn.com/7387d843d15d2dc83eac640681410b47f7997759c36a37520f7e207e2b029bfc-1.jpg),![2.jpg](https://pic.leetcode-cn.com/c331934486b13525ad3e0b9acb88d0665bdeb8b5cdcb3fd5073f675032fdb732-2.jpg),![3.jpg](https://pic.leetcode-cn.com/0d92bbbd51c92bbe227f5303849385021dff53fbb279538aaae3c1a67aa04e09-3.jpg),![1.jpg](https://pic.leetcode-cn.com/cf26c516802d50ee9f5925c5b641b1d7d212e0be9eb688505ac48dc38572255d-1.jpg),![2.jpg](https://pic.leetcode-cn.com/ca297a1151a7489308f3feb8a8998221fd71f6f94956f7b8df3c725b6af07510-2.jpg),![3.jpg](https://pic.leetcode-cn.com/8dfd62451e9eb91a3552f14aa832dfbe9ccb25c510b55eece1cb5d2b521dfc62-3.jpg),![4.jpg](https://pic.leetcode-cn.com/b7fe8416278584265ee4769cbcb5ed0d0d1afec489bafea245b18b1133dce7d5-4.jpg),![5.jpg](https://pic.leetcode-cn.com/13a203dcdb8820927bbc973801098f97118353290197615767ec389416441869-5.jpg)>

```cpp [-C++]
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string result;
        int vecSize = int(strs.size());
        if (vecSize == 0)
        {
            return result;
        }
        if (vecSize == 1)
        {
            return strs[0];
        }
        int min = INT_MAX;
        //获得最小长度
        for (int index = 0; index < vecSize; index++)
        {
            int strSize = strs[index].size();
            if (min > strSize)
            {
                min = strSize;
            }
        }

        for (int increment = 1; increment <= min; increment++)
        {
            string test = strs[0].substr(0, increment);
            for (int index = 1; index < vecSize; index++)
            {
                string compared = strs[index].substr(0, increment);
                if (test != compared)
                {
                    increment--;
                    result = strs[0].substr(0, increment);
                    return result;
                }
            }
        }

        result = strs[0].substr(0, min);
        return result;
    }
};
```

![结局.jpg](https://pic.leetcode-cn.com/ec714cd2f0c027c62316605164b12d52d414922488654c3263182f9a2aeb02a7-%E7%BB%93%E5%B1%80.jpg)
更多内容可以看我制作的视频
https://www.bilibili.com/video/av75856959
