# **题目分析：**
题目直接给出的是node，即让你删除的点。

这和以前数据结构里做过的链表删除很不一样。
一开始想的是数据结构里面学的找头指针然后指向下下一个元素的方法，
但是看了半天题，发现这个题不是那么回事。

看了官方题解才明白，是让你直接把这个点的值改成下一个点的值，然后该点直接指向下下一个点。

```
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
```
**tips：**
注意结构体中指针变量内元素的访问使用“->”，即node->val这样的形式。