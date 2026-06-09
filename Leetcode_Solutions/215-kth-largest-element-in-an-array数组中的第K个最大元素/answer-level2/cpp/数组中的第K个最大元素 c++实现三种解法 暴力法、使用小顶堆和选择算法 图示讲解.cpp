![215.mp4](172ec36b-9f2b-46a3-b23a-ed060b91d0e6)

<![1.jpg](https://pic.leetcode-cn.com/0ec3a7f79bef7eaf22cf2c7398f4aad47091d8ecb01a8eb15307d433dddafff4-1.jpg),![2.jpg](https://pic.leetcode-cn.com/392fe59c664adee72cf2f4a50a704653aadc21d166923c7476928b52c6254c0e-2.jpg),![3.jpg](https://pic.leetcode-cn.com/a4ed6e459a7d5ac7695d7503e1e881e99e15d4363ed3d28f5906c17dc44903d9-3.jpg),![1.jpg](https://pic.leetcode-cn.com/c2a1929230c372968db9268e63b8e79a268dce4039c27a8a8a03d94776272a58-1.jpg),![2.jpg](https://pic.leetcode-cn.com/aab6ba6ff3ba0a5ae8453a61b446107a4fe5d30ed77e5d02e1451d39263ae0e5-2.jpg)>

```cpp [-C++]
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int result = 0;
        int numsSize = int(nums.size());
        if (numsSize == 0 || k > numsSize)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        result = nums[numsSize - k];
        return result;
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/5a8bf5a98dfd56a04da047c137a92972ecdec1bcc6bad964af345b8356c85831-1.jpg),![2.jpg](https://pic.leetcode-cn.com/66627d83ee71ffff2cc216a2a9af702ddb6c728e3d3a3da8398afeb330579bcd-2.jpg),![3.jpg](https://pic.leetcode-cn.com/daff81a86dad30ce6d31ed9ae06fd0069609334730fe302eea3946f2d960f8d0-3.jpg),![1.jpg](https://pic.leetcode-cn.com/13c465eee64b915ab4201f0d014e934d1c0e0037fe99ecbca66c81cfa7d0f7ca-1.jpg),![2.jpg](https://pic.leetcode-cn.com/3c9f351722cd47699d0e732ce4cf201e01112ceee35ce7b59461b9222a4833d1-2.jpg),![3.jpg](https://pic.leetcode-cn.com/274590614615831c057a61aa280c7decf9aba6616e537ecdc9e7779af4284880-3.jpg),![4.jpg](https://pic.leetcode-cn.com/5caee5a44472caf3e47d1b3666049d443d1956403ab1e70fa4e1488e9e786461-4.jpg),![5.jpg](https://pic.leetcode-cn.com/b743afe8079b3c756bb7dc01c5ff2ec66a8ab6f03eee0d60721cd58cc9dad6c2-5.jpg),![6.jpg](https://pic.leetcode-cn.com/3c2797e01a437dd3d2a8ab0fcf072c012bea541b53f6ab844250c6c41c96efd2-6.jpg)>

```cpp [-C++]
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int result = 0;
        int numsSize = int(nums.size());
        if (numsSize == 0 || k > numsSize)
        {
            return 0;
        }

        priority_queue<int, vector<int>, greater<int>> store;
        //堆中维持k个最大数
        for (int i = 0; i < numsSize; i++)
        {
            store.push(nums[i]);
            if (int(store.size()) > k)
            {
                store.pop();
            }
        }

        result = store.top();
        return result;
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/90fc198883851e31aeb54ce911977a33dc13964fc0c94d61a300aa85f1467192-1.jpg),![2.jpg](https://pic.leetcode-cn.com/918fe9cacb24437c9b5eefd746b8772993858d336d69b3e33248228402f2bd14-2.jpg),![3.jpg](https://pic.leetcode-cn.com/f66354ab45f43626e6cb8d70ea126f169233b318977f6a46d60c6cdde687f924-3.jpg),![1.jpg](https://pic.leetcode-cn.com/fd89ca3bdc4a703c0ce865109fdf2a8da587d032fec6b58fab6d443a7965cc10-1.jpg),![2.jpg](https://pic.leetcode-cn.com/7cde3a2f8612dd7ac661b0ac55f7355a18847a56083cc0f19e5ce73da0a9e57a-2.jpg),![3.jpg](https://pic.leetcode-cn.com/758e8f7439d8e423ea32aa743e7ca000b6fa570ab122bc0337624708be6569f0-3.jpg),![4.jpg](https://pic.leetcode-cn.com/c273470c35874cbda7e8c38403c67b6f9ebe5cf535039ae92c7f87211f452f7c-4.jpg),![5.jpg](https://pic.leetcode-cn.com/73d9383143a46ed35c6cd344f5db08b4d9a89e3119f65d7b06e4d12f94173402-5.jpg)>

```cpp [-C++]
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int result = 0;
        int numsSize = int(nums.size());
        if (numsSize == 0 || k > numsSize)
        {
            return 0;
        }
        //寻找第kMIN小的数
        int kMin = numsSize - k + 1;
        result = select(nums, 0, numsSize - 1, kMin);
        return result;
    }

    int select(vector<int> &nums, int left, int right, int target)
    {
        if (left == right)
        {
            return nums[left];
        }
        int cut = partition(nums, left, right);
        //当前第currentResult小的元素
        int currentResult = cut - left + 1;
        if (target == currentResult)
        {
            return nums[cut];
        }
        else if (target < currentResult)
        {
            return select(nums, left, cut - 1, target);
        }
        else
        {
            //寻找接下来第target - currentResult小的数
            return select(nums, cut + 1, right, target - currentResult);
        }
        return 0;
    }

    int partition(vector<int> &nums, int left, int right)
    {
        int cut = nums[right];
        //i指向大堆的最左边的数，j指向下一个判断的数
        int i = left;
        for (int j = left; j < right; j++)
        {
            if (nums[j] <= cut)
            {
                exchange(nums[i], nums[j]);
                i++;
            }
        }
        exchange(nums[i], nums[right]);
        return i;
    }

    void exchange(int &a, int &b)
    {
        int tmpInt = a;
        a = b;
        b = tmpInt;
        return;
    }
};
```

![结局.jpg](https://pic.leetcode-cn.com/f2eace362621487d5a858787b182e80c39f06be36c0120e6a5ad685593006f69-%E7%BB%93%E5%B1%80.jpg)
更多内容可以看我制作的视频
https://www.bilibili.com/video/av75664652

