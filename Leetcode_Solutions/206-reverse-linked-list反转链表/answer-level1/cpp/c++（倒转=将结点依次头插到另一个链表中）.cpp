## 方法一：迭代

### 解题思路
将结点依次添加到另一个链表中，添加方式：头插法

### 代码

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* out = NULL;
        while(head){
            ListNode* tmp = out;
            out = head;
            head = head->next;
            out->next = tmp;
        }
        return out;
    }
};
```

## 方法二：递归

### 解题思路
- 思路：
  - [算法思路的动画演示](https://leetcode-cn.com/problems/reverse-linked-list/solution/dong-hua-yan-shi-206-fan-zhuan-lian-biao-by-user74/)
  - **1_递归出口**：
    - 如果当前节点或者下一个节点为NULL时，直接返回当前节点
      - 情况一：当前节点为NULL。表示链表为空，反转结果也为空。直接返回原链表，结果正确。
      - 情况二：当前节点不为空，下一节点为NULL。表示链表中只有一个元素，反转结果不变。直接返回原链表，结果正确。
  - 2_调用自身：
    - 对输入的next进行递归
  - **3_剩余操作**：
    - （剩余操作在调用自身后面，所以是从后往前迭代）
    - 剩余操作聚焦在**当前输入节点**和**下一个节点**
    - 例子：1->2->3->4<-5 (假设当前节点为3，当前操作聚焦为3->4，后面部分已经反转完成)
      - step 1: 3<-4 (now->next->next=now)
      - step 2: 3->NULL (now->next=NULL)
  - 4_组合解：
    - 每层递归返回值相同，都是最后一个节点的指针（为题目所求：反转后链表的第一个节点）

### 代码

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* out = NULL;
        while(head){
            ListNode* tmp = out;
            out = head;
            head = head->next;
            out->next = tmp;
        }
        return out;
    }
};
```

> -------------------------------------------------
> > \>\>\>[**我的算法题本 - 算法菜鸟之路**](https://github.com/lorwin0130/Algorithm-newbie)
> 会记录做过题的**不同解法、思路、套路总结以及个人思考**
> 欢迎各位大佬**来讨论呀**，欢迎**star (U^_^U)** 
> -------------------------------------------------