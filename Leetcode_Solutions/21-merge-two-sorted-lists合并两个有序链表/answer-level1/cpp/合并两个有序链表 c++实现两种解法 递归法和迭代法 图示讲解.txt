![21.mp4](2754338b-81a0-4b37-a1af-3b00bfb536c9)

<![1.jpg](https://pic.leetcode-cn.com/f11e9707556483531a0dc00bb448786636fea828a96365e5483e030cb3d47588-1.jpg),![2.jpg](https://pic.leetcode-cn.com/2b3588832d51a77a76cc35b0cd714d58cf1e4a5ab7344cc5c3c9a5c5be79b534-2.jpg),![3.jpg](https://pic.leetcode-cn.com/491d9c8a27d521d2c623f237876ce36e6be9bf63e91aa51c8cb0985ef5e8c52f-3.jpg),![1.jpg](https://pic.leetcode-cn.com/71a452fa7c717eaa0613a57c30c1f7fa71a2e87ed8a88ce17764a121aa407c99-1.jpg),![2.jpg](https://pic.leetcode-cn.com/0d09777226ec590e3035316d6900491319cc659e21f37ffb1235a38fad0a8e28-2.jpg),![3.jpg](https://pic.leetcode-cn.com/fef746cb8ae2d8877ad784c64c1ef72c5674b15c69c4c1c83792c9e4b2ea45d5-3.jpg),![4.jpg](https://pic.leetcode-cn.com/a66b4d5297edb9925868663c9dce313f87235d6e596c9d2241641969d42fc89f-4.jpg),![5.jpg](https://pic.leetcode-cn.com/97099c54121133973ed0a512fb275eec84f55a2a2dcc9b4f2469ae60501eb56d-5.jpg),![6.jpg](https://pic.leetcode-cn.com/9fe4230e68e44a4ac968ba5276bb89b6dc905924cc7757265ee958b7a3f5b60e-6.jpg)>

```cpp [-C++]
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
        {
            return l2;
        }
        if (l2 == nullptr)
        {
            return l1;
        }
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/ca767d134315df5742fa04dbc01e45ce59b0e948802047a947a22908cd2b4fbb-1.jpg),![2.jpg](https://pic.leetcode-cn.com/e8ca39bdffcf8e6dd34cb56108d5fce054402748f77022bba6371dae4dcf47a2-2.jpg),![3.jpg](https://pic.leetcode-cn.com/24e8657fb50e3373e0b679adb77f139e6221c50d64c431f11debd42cf8971d50-3.jpg),![1.jpg](https://pic.leetcode-cn.com/e40cc97443a5e4f00c76f01cc133b534489dc1ce2d6a708a1b5a8272344a56d2-1.jpg),![2.jpg](https://pic.leetcode-cn.com/9cb050a438d1b60c49085aac8046ba7c67f7e715e7fd890821d5be92826731fa-2.jpg),![3.jpg](https://pic.leetcode-cn.com/3fba011d97c240d18720e9b1860da4030ee95d62f24afe8b339e66a091578413-3.jpg),![4.jpg](https://pic.leetcode-cn.com/b70feb1e08dddd1fc4141e41372339412756a575fbd2064c56e126c8e8d94c88-4.jpg),![5.jpg](https://pic.leetcode-cn.com/c24db26f0e7093144b2bf41335bd50c78e5daecf22826a3b42335156bfa2e61b-5.jpg),![6.jpg](https://pic.leetcode-cn.com/b12e460611980d9d0feec7cc90b33ba8814b0fa0df463fc817d5d47d63d1ff2c-6.jpg)>

```cpp [-C++]
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode(-1); //哑节点简化代码
        ListNode *workNode = result;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                workNode->next = l1;
                l1 = l1->next;
            }
            else
            {
                workNode->next = l2;
                l2 = l2->next;
            }
            workNode = workNode->next;
        }
        workNode->next = l1 != nullptr ? l1 : l2;

        return result->next;
    }
};
```

![结局.jpg](https://pic.leetcode-cn.com/f5ba401547e85aa7f6155d2e2ef3169a9f71f761b486f98121ce385254035500-%E7%BB%93%E5%B1%80.jpg)
如果你喜欢该回答，希望你能点我的头像关注一下，日更题解哦~
视频地址：
https://www.bilibili.com/video/av76700944
