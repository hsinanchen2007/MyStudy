![2.mp4](62f5ce9c-331d-40d0-9a73-da426b5b5f1c)

<![1.jpg](https://pic.leetcode-cn.com/96bca549edcf4dc1eb98985a41a7f3b3c8b16a24c06fddcc639e1370799a5f37-1.jpg),![2.jpg](https://pic.leetcode-cn.com/74e63124c1d8be46cf9e6aee74018027b852e09ca88f2c406a7f20f5307bd600-2.jpg),![3.jpg](https://pic.leetcode-cn.com/1784a49d1b16f0818abd7b94c5613acee254f34207bfaad3306a1c5d5a4af28b-3.jpg),![4.jpg](https://pic.leetcode-cn.com/ca5021493736fc90a1d8a9ecf5b757e73c4d8c3dcaf6f255f202056f32abee76-4.jpg),![1.jpg](https://pic.leetcode-cn.com/59a43d5bd0c9cfbbb72027eef0ba124ffbe17020d190185b3269d9e6ae6145f7-1.jpg),![2.jpg](https://pic.leetcode-cn.com/96c9e8e0cc57e8727ecff6af6e545c8042e26801de813e2baf4ff3e0fc77fb6f-2.jpg),![3.jpg](https://pic.leetcode-cn.com/f4101f4e1cf30a8cb8ef5ee6aeae872eb08c5b5029132cfc089981197aab6be6-3.jpg),![4.jpg](https://pic.leetcode-cn.com/716a1224f8728885f8d274ce90469b6ad1582ef643a7199b192f5a7c3ce80b48-4.jpg),![5.jpg](https://pic.leetcode-cn.com/f03af71dcc3110b3891b7fd8297256cccb9224f9feca00359a523909e93c26c1-5.jpg)>

```
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int digit = 0;
        int carryDigit = 0;
        ListNode *res = new ListNode(0);
        ListNode *tmpRes = res;

        //carryDigit为进位数
        while (l1 || l2 || carryDigit)
        {
            int tmpSum = 0;
            if (l1)
            {
                tmpSum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                tmpSum += l2->val;
                l2 = l2->next;
            }
            tmpSum += carryDigit;
            digit = tmpSum % 10;
            carryDigit = tmpSum / 10;

            ListNode *newLocation = new ListNode(digit);
            tmpRes->next = newLocation;
            tmpRes = tmpRes->next;
        }

        //删除哑节点
        tmpRes = res->next;
        delete res;
        return tmpRes;
    }
};
```
![结局.jpg](https://pic.leetcode-cn.com/9744150d6e41cfba673e1c0cc92f2513b9f029f1856d325c3c792a1965280fcf-%E7%BB%93%E5%B1%80.jpg)
更多内容可以看我制作的视频
[https://www.bilibili.com/video/av74843896]()

