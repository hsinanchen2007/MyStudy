![15.mp4](7606017c-3e76-44b5-b8cd-9b6e4809dcc1)

<![1.jpg](https://pic.leetcode-cn.com/7c6c0fd77b1e3d59a0603b6641281ab53ac2b935fa8a46aeb71c4a4d6f19c522-1.jpg),![2.jpg](https://pic.leetcode-cn.com/6538a4b99650a8075553f992073c7f57f5764b9d85b85651321d1938e315d547-2.jpg),![3.jpg](https://pic.leetcode-cn.com/a40c93c3c52708d75d34730190d284f52b1351099a0befde5237c32c52541f2e-3.jpg),![1.jpg](https://pic.leetcode-cn.com/df58a3d762532692525f4f130f756fdf8a685c42e0d251b7883927fb6cf294c1-1.jpg),![2.jpg](https://pic.leetcode-cn.com/c0fcb61f32c097ca7eeb4eaa815006bcf910983789383f329380b1e81b24a704-2.jpg),![3.jpg](https://pic.leetcode-cn.com/785e735281804a2150cd4edbb281d2d39160e1d9978e8927c167e426c8c8ef31-3.jpg),![4.jpg](https://pic.leetcode-cn.com/dbc059d775fc9675893d9949b310b83f1763fd92cae3e6f0a1b66e3fbf88b41c-4.jpg),![5.jpg](https://pic.leetcode-cn.com/0454b37a367bb144da6077d95f2e9f72f15a00ab0752bf9beb0039ca7df9794d-5.jpg),![6.jpg](https://pic.leetcode-cn.com/22b78c3aaab2cb6afb3e02fd2191bccbd622a94738fc5727b7c7e7bf507abc45-6.jpg),![7.jpg](https://pic.leetcode-cn.com/1be107f88acb03e8ee4bba60d98dd71a3321c780776d8dfa922e876adf0d64b0-7.jpg),![8.jpg](https://pic.leetcode-cn.com/84694439448f7143d3307271c30ba5b7a116678680ba9589793c44f5b16f73d6-8.jpg),![9.jpg](https://pic.leetcode-cn.com/0d4d25a5424e9dc0f1741fdc5e69d24a98ace66d95ccdf955ddf360f08546ae9-9.jpg)>

```cpp [-C++]
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        int vecSize = int(nums.size());
        if (vecSize <= 2)
        {
            return result;
        }
        int possibleSize = vecSize - 2;
        sort(nums.begin(), nums.end());

        for (int index = 0; index < possibleSize; index++)
        {
            int intNow = nums[index];
            if(intNow > 0){
                break;
            }
            int negativeNow = 0 - intNow;
            int lo = index + 1;
            int hi = vecSize - 1;
            while (lo < hi)
            {
                int intLo = nums[lo];
                int intHi = nums[hi];

                if (intLo + intHi == negativeNow)
                {
                    vector<int> tmpVec{intNow, intLo, intHi};
                    result.push_back(tmpVec);
                    //去重
                    while (lo < hi && nums[lo] == intLo)
                    {
                        lo++;
                    }
                    while (lo < hi && nums[hi] == intHi)
                    {
                        hi--;
                    }
                }
                else if (intLo + intHi < negativeNow)
                {
                    lo++;
                }
                else if (intLo + intHi > negativeNow)
                {
                    hi--;
                }
            }
            //去重
            while (index + 1 < possibleSize && nums[index] == nums[index + 1])
            {
                index++;
            }
        }

        return result;
    }
};
```

![结局.jpg](https://pic.leetcode-cn.com/02184172c31eb6498fc05f0fbac673f471c1bb0c555d4ac4a251fe00c1cb3cca-%E7%BB%93%E5%B1%80.jpg)
更多内容可以看我制作的视频
https://www.bilibili.com/video/av76148668