![16.mp4](c557612e-6a34-48ac-b5de-3f619850987e)

<![1.jpg](https://pic.leetcode-cn.com/36f7ca9ecf5c113a0e5f494718571bd02652b6cc8d07a1f7a656284931caea69-1.jpg),![2.jpg](https://pic.leetcode-cn.com/100d0ec9bc419bfaf3b874fa43ac500e8fb490d13e0b75e39705c1c59d78edeb-2.jpg),![3.jpg](https://pic.leetcode-cn.com/0b88dc1b336f8f41799134c254a36e2c0f8f8a9e5dee75aa3c4c5a5c2491ca58-3.jpg),![1.jpg](https://pic.leetcode-cn.com/3e773f54f469333229b07ec04cdb188ac39904c42a4e31510288930b30b6a0d3-1.jpg),![2.jpg](https://pic.leetcode-cn.com/37aa9ff38f1223b73ee4dfd32d107d7f9b2e830ed3d4075b1d9158cf6a639c3d-2.jpg),![3.jpg](https://pic.leetcode-cn.com/045ebf130119a5c0d18f7722317b624a5285caff33ec10e63ea0ada5570b7c1d-3.jpg),![4.jpg](https://pic.leetcode-cn.com/f03dacbb03f3439bf2c95cc973b5ace726225e5869df822e75e3b39675fc42e4-4.jpg),![5.jpg](https://pic.leetcode-cn.com/04e79f16af6d5c23bfaaf554fb44ba714fcb9189a13c2d5b8768482b52a65f4f-5.jpg),![6.jpg](https://pic.leetcode-cn.com/b238c35c6008735b5503297498d174c3d60b8ef49f8f9401ded0c9e944a891ee-6.jpg),![7.jpg](https://pic.leetcode-cn.com/cb83e1096fedcc33915a67479f78b77a6ac3a29f6fe63f7147670c8fcc6c0273-7.jpg),![8.jpg](https://pic.leetcode-cn.com/d656eb346cfbb13ee16daf7fd8f9eb929db3f349f3330205974744805f88cb8c-8.jpg),![9.jpg](https://pic.leetcode-cn.com/96805de7a92a4c72abdbb429650dc3741b791a5701aa972067c2f8c0357274e1-9.jpg),![10.jpg](https://pic.leetcode-cn.com/562148667c2ad1cac49c1803c57b3995955c304f2d9238f3cb41f260237e476d-10.jpg)>

```cpp [-C++]
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int result = 0;
        int gap = INT_MAX;
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
            int negativeNow = target - intNow;
            int lo = index + 1;
            int hi = vecSize - 1;
            while (lo < hi)
            {
                int intLo = nums[lo];
                int intHi = nums[hi];

                if (intLo + intHi == negativeNow)
                {
                    return target;
                }
                else if (intLo + intHi < negativeNow)
                {
                    int tmpGap = negativeNow - (intLo + intHi);
                    //更新gap
                    if (tmpGap < gap)
                    {
                        gap = tmpGap;
                        result = intNow + intHi + intLo;
                    }
                    while (lo < vecSize && nums[lo] == intLo)//去重，注意别越界
                    {
                        lo++;
                    }
                }
                else if (intLo + intHi > negativeNow)
                {
                    int tmpGap = (intLo + intHi) - negativeNow;
                    //更新gap
                    if (tmpGap < gap)
                    {
                        gap = tmpGap;
                        result = intNow + intHi + intLo;
                    }
                    while (hi >= 0 && nums[hi] == intHi)//去重，注意别越界
                    {
                        hi--;
                    }
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

![结局.jpg](https://pic.leetcode-cn.com/1ad45ccda859d9ebb5e74253af2a345e2f6887d81306e96f52903293cf53709c-%E7%BB%93%E5%B1%80.jpg)
如果你喜欢该回答，希望你能点我的头像关注一下，日更题解哦~
视频地址：
https://www.bilibili.com/video/av76249037

