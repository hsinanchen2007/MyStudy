## 思路一：反转链表元素
取出链表中元素放入vector中，然后将vector中元素逆向存入链表中。
1. 遍历链表，用vector存放数组元素。
2. 再次遍历链表，从vector尾部读取元素依次放入链表中。

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
        return head;
    }
    vector<int> res;        
    ListNode *pNode = head;
    while (pNode != nullptr) {
        res.push_back(pNode->val);
        pNode = pNode->next;
    }
    vector<int>::reverse_iterator iter = res.rbegin();
    pNode = head;
    while (pNode != nullptr) {
        pNode->val = *iter;
        iter++;
        pNode = pNode->next;
    }
    return head;
}
```

## 思路二：迭代
需要调整当前元素指针指向前一个元素，必须先存储其前一个元素，另外为了继续遍历链表，在改动指针前，还需要存储下一个节点。新头结点为最后保存的前一个元素。

### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
        return head;
    }
    ListNode *cur = head;
    ListNode *pre = nullptr;
    while (cur != nullptr) {
        ListNode *next = cur->next;//保存当前节点下一个节点
        cur->next = pre;//反转指针
        pre = cur;//分别移动pre和cur
        cur = next;
    }
    return pre;
}
```

## 思路三：递归
通过递归反转链表后面的元素，递归终止条件为当前节点为空或下一个节点为空。现在对头节点进行反转，假设链表此时为：
head -> n1 <- n2... <-n
对头结点进行反转：head->next->next = head;
然后将头节点next设为nullptr。

### 代码
时间复杂度：O(n)
空间复杂度：O(n)，由于使用递归，会使用隐式栈空间，递归深度可能达到n层。
```c++
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *p = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}
```
