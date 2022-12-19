## 解题思路


我们的目的是将两个有序链表合并成一个有序链表，因此，我们的每次操作都是获取 $l1$ 指向的结点和 $l2$ 指向的结点中，值较小的结点。迭代和递归都是如此。



- 使用迭代的时候

  - 为了将第一个结点与其余结点统一处理，一般会定义一个头结点。

- 使用递归的时候

  - 我们往往可以利用递归函数的返回值，将处理好的链表的第一个结点，作为返回值返回到上一级。

  - 上一级函数则直接将得到的返回值，链接在当前结点的 $next$ 即可。



## 迭代

- 定义头结点
- 若 $l1$ 指向的结点值 $<$ $l2$ 指向的结点值，则将 $l1$ 链接到头结点的 $next$ 位置
- 否则将 $l2$ 链接到头结点的 $next$ 位置
- 循环进行，直至 $l1$ 或 $l2$ 为 $NULL$
- 最后，将 $l1$  或  $l2$ 中剩下的部分，链接到头结点后面



#### 代码

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(1);
        ListNode* ret = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        head->next = l1 == NULL ? l2 : l1;
        return ret->next;
    }
};
```



## 递归

编写递归的第一步，应当是明确当前函数应当完成的功能。

- 函数功能
  - 返回 $l1$ 指向的结点和 $l2$ 指向的结点中，值较小的结点
  - 并将从下级函数获得的返回值，链接到当前结点尾部

- 函数结束条件
  - 当 $l1$ 为空，或 $l2$ 为空，函数结束
  - 返回 $l1$  或  $l2$ 中剩下的部分



#### 代码

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
};
```



## 最后

感谢您的观看！欢迎大家留言，一起讨论交流。

至此，您已经学会使用迭代和递归来合并两个有序链表，如果这篇文章对您有帮助，您可以扫描下方二维码关注我的公众号“小小算法”，感谢您的支持！

![小小算法.png](https://pic.leetcode-cn.com/1776597b2773892787b2a16738cd78feb346c5a5290273bce69275b0b66a0a95-%E5%AE%A3%E4%BC%A0%E5%9B%BE2.png)