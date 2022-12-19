速度肯定是慢的因为我这样搜索节点的话必须从头往后走，单链表好像常数时间搜索有点难度，我没做到。。。

√ Accepted

  √ 61/61 cases passed (56 ms)

  √ Your runtime beats 98.71 % of cpp submissions

  √ Your memory usage beats 73.43 % of cpp submissions (19.3 MB)

如果设置一个中间节点的话，在要搜索的节点处于后半部分的话会快很多，或者有别的改进方法吧

```
/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */
class MyLinkedList {
 public:
  /** Initialize your data structure here. */
  typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(nullptr) {}
  } n;
  MyLinkedList() {}

  /** Get the value of the index-th node in the linked list. If the index is
   * invalid, return -1. */
  int get(int index) {
    if (index >= size || index < 0) return -1;
    p = front;
    while (index--) p = p->next;
    return p->val;
  }

  /** Add a node of value val before the first element of the linked list. After
   * the insertion, the new node will be the first node of the linked list. */
  void addAtHead(int val) {
    p = new n(val);
    if (!size++)
      tail = p;
    else
      p->next = front;
    front = p;
    return;
  }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val) {
    p = new n(val);
    if (!size++)
      front = p;
    else
      tail->next = p;
    tail = p;
    return;
  }

  /** Add a node of value val before the index-th node in the linked list. If
   * index equals to the length of linked list, the node will be appended to the
   * end of linked list. If index is greater than the length, the node will not
   * be inserted. */
  void addAtIndex(int index, int val) {
    if (index > size) return;
    if (index <= 0) return addAtHead(val);
    if (index == size) return addAtTail(val);
    indexnew = new n(val);
    p = front;
    while (--index) p = p->next;
    tmp = p->next;
    p->next = indexnew;
    indexnew->next = tmp;
    ++size;
    return;
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index) {
    if (index < 0 || index >= size) return;
    if (!index) {
      front = front->next;
      --size;
      return;
    }
    p = front;
    indextmp = index;
    while (--index) p = p->next;
    p->next = p->next->next;
    if (indextmp == size - 1) tail = p;
    --size;
    return;
  }

 private:
  int size = 0, indextmp;
  n *front = nullptr, *p = nullptr, *tail = nullptr, *tmp = nullptr,
    *indexnew = nullptr;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


```