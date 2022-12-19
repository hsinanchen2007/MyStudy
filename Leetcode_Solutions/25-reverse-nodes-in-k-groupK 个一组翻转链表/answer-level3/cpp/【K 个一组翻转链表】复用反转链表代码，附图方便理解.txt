### 思路
1. K 个一组反转链表，直白的想一想就是数 K 个，反转一下，数 K 个，反转一下
2. 数 K 个，很简单，一个循环搞定
3. 反转链表，[206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)，[我的题解](https://leetcode-cn.com/problems/reverse-linked-list/solution/206-by-ikaruga/)
4. 把 2 和 3 组合起来
5. 将其中一段链表反转，还需要解决的细节问题
    51. 需要使用 `dummy` 来保存要返回的头节点
    52. 要知道这段链表的前一个节点 `pPrev` ，这样才能把它的 `next` 指向反转之后的新链表头
    53. `pPrev` 的 `next` 节点刚好是他要指向下一段链表之前的节点，所以调用反转的时候需要一个 `pTemp` 周转一下
    54. 反转后的新链表要继续链接原链表之后的节点
    > 注意到反转的链表函数其实是有这个功能的，举例来说：`1->2->3->nullptr` 反转后是 `3->2->1->nullptr`
    > `nullptr` 即是原链表的后面节点，所以只需要对函数做一点点修改，使用 `tail` 替代 `nullptr`

### 图解
```
输入：[1,2,3,4,5]，k = 3
输出：[3,2,1,4,5]
```
<![图片.png](https://pic.leetcode-cn.com/a1a9b593d9741797a57c3da24c28ff73d515141f3119a2b4c17049eb143555aa-%E5%9B%BE%E7%89%87.png),![图片.png](https://pic.leetcode-cn.com/5123eb7c71ee4360dedd1f9af23d0d76b7290e93a0d876ea72365d451098de32-%E5%9B%BE%E7%89%87.png),![图片.png](https://pic.leetcode-cn.com/0c6a127275b83962e9aae309e6e1208b4fcc10a9b288cab99ffd94ae9df0c4c3-%E5%9B%BE%E7%89%87.png),![图片.png](https://pic.leetcode-cn.com/763258f61678fa551c83d3d02fcc4b8040108de1305b9f3d7011515b7dcd25d8-%E5%9B%BE%E7%89%87.png)>


### 答题
```C++ []
ListNode* reverseList(ListNode* head, ListNode* tail)
{
    ListNode* pPrev = tail;
    ListNode* pCurr = head;
    while (pCurr != tail)
    {
        ListNode* pNext = pCurr->next;
        pCurr->next = pPrev;
        pPrev = pCurr;
        pCurr = pNext;
    }
    return pPrev;
}

ListNode* reverseKGroup(ListNode* head, int k)
{
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pPrev = dummy;
    ListNode* pCurr = head;
    while (pCurr != nullptr)
    {
        int i = 0;
        while (i++ < k && pCurr != nullptr)
        {
            pCurr = pCurr->next;
        }
        if (i != k + 1) break;

        ListNode* pTemp = pPrev->next;
        pPrev->next = reverseList(pTemp, pCurr);
        pPrev = pTemp;
    }
    return dummy->next;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

