![4.mp4](53f40e99-2988-4719-97c4-47a155933b3e)

<![1.jpg](https://pic.leetcode-cn.com/30395efce3500449e90b19a349eef5d9059d00a5c0ef69d58021b848b12c4a27-1.jpg),![2.jpg](https://pic.leetcode-cn.com/8d200fffd10e755b3d4c62ee2d9f571bef7d9ae67d62334adc7d7e5df4e19b61-2.jpg),![3.jpg](https://pic.leetcode-cn.com/14ded8aafa23cd31383ec9cdf8dba4da75c2c7edfe6aa3342eff6e14a9266bad-3.jpg),![1.jpg](https://pic.leetcode-cn.com/88a41c56262c5f0bfef682d800a9852bb4f39f665e0a77e73589c0f2c7a57e41-1.jpg),![2.jpg](https://pic.leetcode-cn.com/ab10b8c4d21665677dd97c9ae4e9d7064d7d6d0e589bc431fabc5f120debfe11-2.jpg),![3.jpg](https://pic.leetcode-cn.com/b4ffad1dc9cfa5eb12ac52b926e5768e28cc7802e388764dba16d9e1611dd8a4-3.jpg),![1.jpg](https://pic.leetcode-cn.com/e843179e7a5ea4ff6932c802d7e1db22d9314d79bd9d363c0ec76b256497f345-1.jpg),![2.jpg](https://pic.leetcode-cn.com/195bcd7fb9ab2716949b81a08e58ad3bd2cb1e1632ce365b84df358d0aa607dc-2.jpg),![3.jpg](https://pic.leetcode-cn.com/f90f63113709fec7d30f535db4d7403d10f2b6f9fc8f685dbbcb951af82c6817-3.jpg),![1.jpg](https://pic.leetcode-cn.com/c58a6e18545e7ebe4e180f850edf92b5928528cff71bba3fdd715c2761e6bbd5-1.jpg),![2.jpg](https://pic.leetcode-cn.com/35e09552262bbd2a8d4b49f7772da5226eaadbd3c23b523b9627846ffc33ab6d-2.jpg),![3.jpg](https://pic.leetcode-cn.com/1e9a8e67d7a610f92425d44f9dd9633f9f138b0856e253cca5a8805c9385009a-3.jpg)>

```
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int nums1Size = int(nums1.size());
        int nums2Size = int(nums2.size());

        //确保数组1是较短的数组
        if (nums1Size > nums2Size)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        // Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。lMaxi为第i个数组割后的左元素。rMini为第i个数组割后的右元素。
        int lMax1, lMax2, rMin1, rMin2, c1, c2, lo = 0, hi = 2 * nums1Size; //我们目前是虚拟加了'#'所以数组1是2*n长度

        while (lo <= hi)
        { //二分法
            c1 = (lo + hi) / 2;
            c2 = nums1Size + nums2Size - c1;

            lMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            rMin1 = (c1 == 2 * nums1Size) ? INT_MAX : nums1[c1 / 2];
            lMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            rMin2 = (c2 == 2 * nums2Size) ? INT_MAX : nums2[c2 / 2];

            if (lMax1 > rMin2)
            {
                hi = c1 - 1;
            }
            else if (lMax2 > rMin1)
            {
                lo = c1 + 1;
            }
            else
            {
                break;
            }
        }
        return (max(lMax1, lMax2) + min(rMin1, rMin2)) / 2.0;
    }
};
```
![结局.jpg](https://pic.leetcode-cn.com/dd282b6d24ee26fa572a47f8841bc3df26251f4d6980d22b8a3c5a1576fa82df-%E7%BB%93%E5%B1%80.jpg)
更多内容可以看我制作的视频
https://www.bilibili.com/video/av74952167
