### 解题思路
根据题意，我们先将链表在$n/2$的位置分割成两部分，前半部分保持原序列，后半部分翻转。
以`1->2->3->4->5`为例，经这一操作后变为`1->2->3<-4<-5`，`3->NULL`。
最后再将“两个”链表拼接起来即可。

### 代码
话不多说上代码：
```cpp
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* tmp = head;
        int n = 0;
        while (tmp != NULL) {
            tmp = tmp->next;
            n++;
        }

        ListNode* res = head;
        for (int i = 0; i < (n / 2); i++) {
            head = head->next;
        }

        ListNode* pre = NULL;
        while (head != NULL) {
            tmp = head->next;  // 先把head->next存起来
            head->next = pre;
            pre = head;
            head = tmp;  // 最后再还回来
        }  // 1->2->3<-4<-5

        // 把两个链表拼起来
        ListNode* head1 = res;  // 1
        ListNode* head2 = pre;  // 5
        for (int i = 0; i < (n - 1); i++) {
            if (i & 1) {
                tmp = head2->next;
                head2->next = head1;
                head2 = tmp;
            }
            else {  // 偶数
                tmp = head1->next;
                head1->next = head2;
                head1 = tmp;
            }
        }
    }
};
```

### 复杂度分析
时间复杂度：$O(n)$，一共遍历了3次。
空间复杂度：$O(1)$，只需要常数级的额外指针。

### 结果
马马虎虎~
![微信截图_20200218112026.png](https://pic.leetcode-cn.com/d82dd335f2d160fc10f51f4372d7d94624ba8778f463765072ac5a5a4289d0f6-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200218112026.png)
