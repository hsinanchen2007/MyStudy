![11.mp4](12f9a33e-8b7b-470a-ac8a-8d77bea0ab04)

<![1.jpg](https://pic.leetcode-cn.com/923624cc904849ecad6813cf993c9b7aeca67df539756382b9ea1c4792fca8ab-1.jpg),![2.jpg](https://pic.leetcode-cn.com/cff22054322a84b5de5e1ae05630fea307f188ba9809fa2fb7cb0b7d9611b870-2.jpg),![3.jpg](https://pic.leetcode-cn.com/78895a13a56a769686b6e378b0112b29e81f858873d06d9b005cb309492fd00b-3.jpg),![1.jpg](https://pic.leetcode-cn.com/cc315026812711a7f297f4b7de887a2163aa8d3ec0096e95e403c1dddef2a372-1.jpg),![2.jpg](https://pic.leetcode-cn.com/badc2a8a11e4f9e953d6d7fc1aea1cbcb417140fa90af9eb8feba361b665831f-2.jpg),![3.jpg](https://pic.leetcode-cn.com/be63aebcf4948bbaf7250deb08476bdd630169702910bede0abd8cbb5e5bba9e-3.jpg),![4.jpg](https://pic.leetcode-cn.com/e6cb0a24d2d5a438c834a2f1c86c56b939ad0ae50ac6139f352bb65ebef4cff8-4.jpg),![5.jpg](https://pic.leetcode-cn.com/5b7099d3e49869f4a2f49bb3c60bbbaab6b24118634a933e1079ef5e80fed9f0-5.jpg),![6.jpg](https://pic.leetcode-cn.com/f5a0db4f9a5977fdfecd545197d4831112a0c6e520b1507096633f9d92bf9266-6.jpg),![7.jpg](https://pic.leetcode-cn.com/fd68a278900dc62c51cdea37a8078b5fa21aefecdcf7410da0189a6a776bace4-7.jpg)>

```cpp [-C++]
#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int result = 0;
        int heightSize = int(height.size());
        for (int index1 = 0; index1 < heightSize; index1++)
        {
            for (int index2 = index1 + 1; index2 < heightSize; index2++)
            {
                int length = index2 - index1;
                int heightSize = height[index1] < height[index2] ? height[index1] : height[index2];
                int tmpSize = length * heightSize;
                if (tmpSize > result)
                {
                    result = tmpSize;
                }
            }
        }
        return result;
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/dd3a86631e254bc4c38993f7a8627f880fbc242bb482b27643a5411f486b1be2-1.jpg),![2.jpg](https://pic.leetcode-cn.com/04e2b7b1127322a38163f951f766a82fc8c9dae8e2e8fe57f2ef802b3ec3f28b-2.jpg),![3.jpg](https://pic.leetcode-cn.com/bf412202ac7eedc56ac407468aeaa6ece84842ee8ac756a065265aaf5827a6d3-3.jpg),![1.jpg](https://pic.leetcode-cn.com/f42baef20dd358be14e277cd08d27d4cffa7334b64aa6e2f4d13ff26be6688e8-1.jpg),![2.jpg](https://pic.leetcode-cn.com/50dca21435b3852d6b010a9c6d0e22cde326d917bf9c8b66edde20c0ee7e4dc1-2.jpg),![3.jpg](https://pic.leetcode-cn.com/e7026b32989ca39d156082318ffe8a85a8255ab016d6c7512c97f4d9095f6d76-3.jpg),![4.jpg](https://pic.leetcode-cn.com/7c656d87c3bb851a7a1af6af2b2c677dde17d7be0232fba035e2f7fb516c5195-4.jpg),![5.jpg](https://pic.leetcode-cn.com/bb574f5e426e96f59d09a6f9a1a081da5d8a31fe0c3038c97ebe51c39950c77b-5.jpg)>

```cpp [-C++]
#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int result = 0;
        int heightSize = int(height.size());
        int leftIndex = 0;
        int rightIndex = heightSize - 1;

        while (leftIndex != rightIndex)
        {
            int tmpHeight;
            int tmpWidth = rightIndex - leftIndex;
            //短的一侧向中间移动
            if (height[leftIndex] < height[rightIndex])
            {
                tmpHeight = height[leftIndex];
                leftIndex++;
            }
            else
            {
                tmpHeight = height[rightIndex];
                rightIndex--;
            }
            int tmpResult = tmpWidth * tmpHeight;
            if (tmpResult > result)
            {
                result = tmpResult;
            }
        }
        return result;
    }
};
```

![结局.jpg](https://pic.leetcode-cn.com/738d8bfe372f8e0c10734e32ad4d4dfa8f47c35a0b57b4f2da57edb9fcecce36-%E7%BB%93%E5%B1%80.jpg)
更多内容可以看我制作的视频
https://www.bilibili.com/video/av75562857