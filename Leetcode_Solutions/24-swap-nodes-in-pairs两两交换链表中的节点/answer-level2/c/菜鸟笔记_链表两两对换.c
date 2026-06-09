### 解题思路
思路挺简单，涉及四个指针，**每次操纵两个节点**（题目给的链表成为“旧链表”， 返回去的链表称为“新链表”）：
1. retHead指针，用来记录返回链表的头，只在最后的动一下（retHead刚开始为了统一操作只是充当空的头节点，最后向后挪一个，指到实际头节点）；
2. h节点，用来作为新链表的尾巴节点，每次做新的插入时启动；
3. p节点，用来记录旧链表里面的第一个节点。
4. head指针，同时充当旧链表里面的第二个节点，并且记录剩下来的链表的头部。

**初始的时候链表指针如下：**
![链表.jpg](https://pic.leetcode-cn.com/86cb073f15dad87356e90837ffc33137661cd947b69934fc62216f771cc4f638-%E9%93%BE%E8%A1%A8.jpg)

**有些细节需要注意：**
1. 空链表
2. 单个节点
4. 奇数个节点，奇数的时候最后一个节点直接插入到新链表的最后。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* retHead = NULL;//返回头节点
    struct ListNode* h = NULL;
    struct ListNode* p = NULL;
    int cnt = 1;

    retHead = (struct ListNode*)malloc(sizeof(struct ListNode));//新申请的链表头节点
    h = retHead;
    
    if (head == NULL)//空节点
    {
        return head;
    }
    /*head ！= NULL 实际上是为了检查是否为奇数个节点，因为循环里面要后退两次，所以如果后退偶数次，head为空了，那么必是奇数个节点
    head->next != NULL 是为了防止数组越界，同样因为里面h后退了两次head,如果不加以判断会报错。
    */
    while (head != NULL && head->next != NULL)
    {
        p = head;
        head = head->next;
        h->next = head;
        head = head->next;
        h = h->next;
        h->next = p;
        p->next = NULL;
        h = p;
    }
    
    h->next = head;//奇数个节点的时候有实际作用
    retHead =retHead->next;

    return retHead;

}
```