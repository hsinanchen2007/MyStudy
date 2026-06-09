![18.mp4](224acf93-32a3-485f-8ead-ab9e0dffaa61)

<![1.jpg](https://pic.leetcode-cn.com/1c4d1509b6b0fcc5873eedc6fbb6b6ede479eaf033968e77034c7895a929d0fb-1.jpg),![2.jpg](https://pic.leetcode-cn.com/46b2e1719555dc764ac95765388da8a28181ecc1bdea0f6defb2faabc6475b63-2.jpg),![3.jpg](https://pic.leetcode-cn.com/108200a97b14dc1c9befa23901057c1331e623a57876d6838129e652eb59ce6c-3.jpg),![1.jpg](https://pic.leetcode-cn.com/cd06fbc9d2bb1eecb798333f4253adc46c2a88f8ee717e53ca6c1b463547329a-1.jpg),![2.jpg](https://pic.leetcode-cn.com/14084e97fed12286efa8ea66e5d569e4e620b9512700341e1e96b549c56ccec0-2.jpg),![3.jpg](https://pic.leetcode-cn.com/7fdc4c648ce3c3bd0ddfecd3b31159f594b4d1a22cd52a97851614c76709220b-3.jpg),![4.jpg](https://pic.leetcode-cn.com/c0869fc85f231bf57a897081d724cb81dcbf78bbab2b80aec475b1b357d8c95d-4.jpg),![5.jpg](https://pic.leetcode-cn.com/15b23a7db43c969d8f5a49af702feaf3d0a82654834c44b90195ccb5adc74018-5.jpg),![6.jpg](https://pic.leetcode-cn.com/c6e5e6d018f20282662b6719c4e87f9d2a973af7fbe77edd0614086a60fb2cde-6.jpg),![7.jpg](https://pic.leetcode-cn.com/07523a191f4ddcc369a6b8badebe30d4a1bbc28a6728238fce12c3858826fd74-7.jpg)>

```cpp [-c++]
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        auto vecSize = nums.size();
        if (vecSize <= 3)
        {
            return result;
        }
        auto possibleSize = vecSize - 3;
        sort(nums.begin(), nums.end());
        for (vector<int>::size_type i = 0; i < possibleSize; ++i)
        {
            for (vector<int>::size_type j = i + 1; j < possibleSize + 1; ++j)
            {
                int intNow = nums[i];
                int intSecond = nums[j];
                int negativeNow = target - intNow - intSecond;
                vector<int>::size_type lo = j + 1;
                vector<int>::size_type hi = vecSize - 1;
                while (lo < hi)
                {
                    int intLo = nums[lo];
                    int intHi = nums[hi];

                    if (intLo + intHi == negativeNow)
                    {
                        vector<int> tmpVec{intNow, intSecond, intLo, intHi};
                        result.push_back(tmpVec);
                        //去重
                        while (lo < hi && nums[lo] == intLo)
                        {
                            ++lo;
                        }
                        while (lo < hi && nums[hi] == intHi)
                        {
                            --hi;
                        }
                    }
                    else if (intLo + intHi < negativeNow)
                    {
                        ++lo;
                    }
                    else if (intLo + intHi > negativeNow)
                    {
                        --hi;
                    }
                }
                //去重
                while (j + 1 < possibleSize + 1 && nums[j] == nums[j + 1])
                {
                    ++j;
                }
            }
            //去重
            while (i + 1 < possibleSize && nums[i] == nums[i + 1])
            {
                ++i;
            }
        }
        return result;
    }
};
```

![结局.jpg](https://pic.leetcode-cn.com/c7b6a190a94b3099cb3b47a4e3d3472dd8d64a60dc086c6579a8ace163ecf6bf-%E7%BB%93%E5%B1%80.jpg)
如果你喜欢该回答，希望你能点我的头像关注一下，日更题解哦~
视频地址：
https://www.bilibili.com/video/av76355742