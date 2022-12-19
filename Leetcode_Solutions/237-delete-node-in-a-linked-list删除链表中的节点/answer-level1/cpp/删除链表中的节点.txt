# C/C++两种方式效率对比

下面两种方式在本质上是相同的，都是将当前节点指针指向给定节点指向的下一个节点，但是执行效率有明显区别

## 第一种
```
/*
* 执行用时 :24 ms, 在所有 C++ 提交中击败了37.86%的用户
* 内存消耗 :9.3 MB, 在所有 C++ 提交中击败了5.55%的用户
*/
void deleteNode(ListNode *node)
{
    ListNode *p = node->next;
    *node = *p;
    p->next = nullptr;
    delete p;
}
```
## 第二种
```
/*
* 执行用时 :12 ms, 在所有 C++ 提交中击败了99.62%的用户
* 内存消耗 :9 MB, 在所有 C++ 提交中击败了88.01%的用户
*/
void deleteNode(ListNode *node)
{
    ListNode *p = node->next;
    node->val = p->val;
    node->next = p->next;
    p->next = nullptr;
    delete p;
}
```

