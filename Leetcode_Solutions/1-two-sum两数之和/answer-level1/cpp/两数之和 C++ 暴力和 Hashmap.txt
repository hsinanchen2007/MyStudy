![1.mp4](e276f5e7-0f04-4007-bae1-85846eec0478)

<![0.jpg](https://pic.leetcode-cn.com/d2b08ab8d5a42cb4f0a5ccf1a29a26c4623010fdd22808bf37a048be615dfe33-0.jpg),![1.jpg](https://pic.leetcode-cn.com/d3ce5f526c2a59df6d4bbfa0ac8052aab6f7454d283212fb49d5f6a4ffe7c750-1.jpg),![2.jpg](https://pic.leetcode-cn.com/ab3e6a24ca8ef1f9b41bc8a20993cd658dd56fb3530e0e289dbe76839ac8aefc-2.jpg),![1.jpg](https://pic.leetcode-cn.com/60530eaeda0d98f21b54fe5a6dbad4b65de822a8fd1688df903595aa4597bc9d-1.jpg),![2.jpg](https://pic.leetcode-cn.com/39a7d9df243d9a4a63da0d5f8bdf677163a5954493a58d56e2393de979bbcb89-2.jpg),![3.jpg](https://pic.leetcode-cn.com/f1d87103d081a6800aac37aad3c4e4809fea797cab9b76d89ac61139a87273f0-3.jpg)>
```cpp [-C++]
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        int numsSize = int(nums.size());

        for (int index = 0; index < numsSize; index++)
        {
            int b = target - nums[index];
            //注意index2 = index + 1，数字不能重复使用
            for (int index2 = index + 1; index2 < numsSize; index2++)
            {
                if (nums[int(index2)] == b)
                {
                    res.push_back(index);
                    res.push_back(index2);
                    return res;
                }
            }
        }
        return res;
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/baff41ccd84486277df18a7faee6842740f27fc973dcda3f9b5494746bef287e-1.jpg),![2.jpg](https://pic.leetcode-cn.com/cf0f2055466d884f3d5355f3bed6c26da73055c7bc7d0080ccf0c80963fd05cf-2.jpg),![3.jpg](https://pic.leetcode-cn.com/81c0de84523d90b14a2eddb0ee2f8462ae09ff4bfe0064ebf16c110ddcda36c4-3.jpg),![1.jpg](https://pic.leetcode-cn.com/58c0832ca111e387afdce545b95f8b157bfcfa021db73b130de277eed599d000-1.jpg),![2.jpg](https://pic.leetcode-cn.com/f73179dfcfe6362db2ecabd93c1966ccbe9a8a0a574afc802cd26b0d0bfa19e4-2.jpg),![3.jpg](https://pic.leetcode-cn.com/47656e7e3c1b5c6d02e66f01e69b3699a10564fedd5709b344ba5c690e6ca18f-3.jpg),![4.jpg](https://pic.leetcode-cn.com/62b92594190d9e4d418826125aa94711fe8d37809b3aba3729d019477bd6039f-4.jpg)>

```cpp [-C++]
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        //Key是数字，value是该数字的index
        unordered_map<int, int> hash;
        vector<int> result;
        int numsSize = int(nums.size());
        for (int i = 0; i < numsSize; i++)
        {
            int numberToFind = target - nums[i];

            //如果找到numberToFind，就return
            if (hash.find(numberToFind) != hash.end())
            {
                result.push_back(hash[numberToFind]);
                result.push_back(i);
                return result;
            }

            //如果没有找到，把该数字的index放到hash表中
            hash[nums[i]] = i;
        }
        return result;
    }
};
```

![结局.jpg](https://pic.leetcode-cn.com/ae0a0d43b0dec9f3384f9b8a863ed9198d1fd0259cf04c48bb3ec62ad9ca9ae4-%E7%BB%93%E5%B1%80.jpg)

更多内容可以看我制作的视频
[https://www.bilibili.com/video/av74780617]()