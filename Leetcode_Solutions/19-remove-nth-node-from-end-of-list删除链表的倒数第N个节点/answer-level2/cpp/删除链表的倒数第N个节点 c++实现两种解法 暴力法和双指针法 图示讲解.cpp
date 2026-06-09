![19.mp4](f0648227-5f0a-4697-a5ac-edde76896e39)

<![1.jpg](https://pic.leetcode-cn.com/ba24ec564d6f83b98c6ae653845b1855c5ee42bc671baa7853faf48988b498d6-1.jpg),![2.jpg](https://pic.leetcode-cn.com/b6aa5342c00cb66b67c36f17de968d46995cae1674111cd2079b936fcd203005-2.jpg),![3.jpg](https://pic.leetcode-cn.com/7759c95466b35025326219f1a54b880889f58166f9ae166bc298ab53d5f8dcb3-3.jpg),![1.jpg](https://pic.leetcode-cn.com/3feaa04b216a0ffe477c4f82c2f689a6d593625ba85d5cfbe5b223bbf6c69ae9-1.jpg),![2.jpg](https://pic.leetcode-cn.com/4aba1fb8ae88ea94fb1def214914759b9e595e60b54891e235d1ba78be7eec51-2.jpg),![3.jpg](https://pic.leetcode-cn.com/f965919528e1ec2441505930bf485952d60b1f08c2cb36db0b3e09b784fd0100-3.jpg),![4.jpg](https://pic.leetcode-cn.com/430c8ad9285d93b98ee3823a7b6955833f3dac73d08e37b0e8c227613f68b880-4.jpg),![5.jpg](https://pic.leetcode-cn.com/c22db194470e7b86c7e0dd3c645a276bf6b59f3bd5436274ab7ad732d9cc413c-5.jpg),![6.jpg](https://pic.leetcode-cn.com/c292905287fa29fbabee925630c8cf8d81d00f8aa3ecee5761a21a88e6f17bfc-6.jpg)>

```cpp [-C++]
#include <iostream>
using namespace std;

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *workNode = head;
        int size = 0;
        while (workNode != nullptr)
        {
            workNode = workNode->next;
            size++;
        }
        int target = size + 1 - n;

        workNode = dummyNode;
        for (int times = 1; times < target; ++times)
        {
            workNode = workNode->next;
        }
        //跳过被删除的元素
        workNode->next = workNode->next->next;
        return dummyNode->next;
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/04c32579e4009d1fadf94ea9a880f26ced6d46f0a4b7f24b5fd07779b86be358-1.jpg),![2.jpg](https://pic.leetcode-cn.com/12097bbc40fdd82cbc5278211509f7ee0556944b746cd1558eaa1bca725ea676-2.jpg),![3.jpg](https://pic.leetcode-cn.com/b457f2ff31473ca93ff406b1992dbb024a8c45e6949574461dbf66a5321211dd-3.jpg),![1.jpg](https://pic.leetcode-cn.com/3f406fda5442691545a804a27e467f2ef0c4c43585d57c12332b6ca54bac88df-1.jpg),![2.jpg](https://pic.leetcode-cn.com/94eb29fb6e17c7b864703b277a793806b6a350b9735cd47babf2512e4cff690d-2.jpg),![3.jpg](https://pic.leetcode-cn.com/0c2153d07f73f2a39cc5be59bf827e573aad7c98727e140c3ddff34761ba8d95-3.jpg),![4.jpg](https://pic.leetcode-cn.com/001c24db7db6f96c01d8100140327794979374c801f46a3dee93ecd9d2fcee7b-4.jpg),![5.jpg](https://pic.leetcode-cn.com/8d69e98710268fa964d19241296f489cdb1a24935b24b8bb50e2714c1607565b-5.jpg),![6.jpg](https://pic.leetcode-cn.com/5bcef8c1c5d730f76c73d745e1131f5bb8b39ffbd2e1d6f76e20034b808e7db2-6.jpg),![7.jpg](https://pic.leetcode-cn.com/e07e3f590f2abb948ce3ce3f4ab140468114323dffbfc75e35bf1c7cfd18cd61-7.jpg)>

```cpp [-C++]
#include <iostream>
using namespace std;

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *firstNode = dummyNode, *secondNode = dummyNode;
        for (int i = 1; i <= n; ++i)
        { //注意考虑边界条件
            secondNode = secondNode->next;
        }
        while (secondNode->next != nullptr)
        {
            secondNode = secondNode->next;
            firstNode = firstNode->next;
        }
        firstNode->next = firstNode->next->next;

        return dummyNode->next;
    }
};
```

![结局.jpg](https://pic.leetcode-cn.com/f060ad315e73b5ccd1464daf4dbd75174304f5015d1b99d54dc3d3eefaf96883-%E7%BB%93%E5%B1%80.jpg)
如果你喜欢该回答，希望你能点我的头像关注一下，日更题解哦~
视频地址：
https://www.bilibili.com/video/av76364280