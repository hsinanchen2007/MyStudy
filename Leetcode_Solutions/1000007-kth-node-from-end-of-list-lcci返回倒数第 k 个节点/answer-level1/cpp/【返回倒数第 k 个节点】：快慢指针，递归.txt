#### 快慢指针

- 定义两个指针，快指针 $fast$， 慢指针 $low$ .
- 让 $fast$ 先向前移动 $k$ 个位置，然后 $low$ 和 $fast$ 再一起向前移动 .
- 当 $fast$ 到达链表尾部，返回 $low$ .



#### 代码

```cpp
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* low = head;
        while (fast != NULL) {
            fast = fast->next;
            if (k == 0) {
                low = low->next;
            } else {
                k--;
            }
        }
        return low->val;
    }
};
```



#### 递归

- 先一直递归到链表尾部，再返回
- 定义位置变量 $pos$ ，每次函数返回时 $pos++$ 
- 当 $pos == k$ 时，说明此时递归函数位于第 $k$ 个结点位置，返回结点值



#### 代码

```cpp
class Solution {
public:
    int pos = 0;
    int kthToLast(ListNode* head, int k) {
        if (head == NULL) {
            return 0;
        }
        int ret = kthToLast(head->next, k);
        pos++;
        if (pos == k) {
            return head->val;
        }
        return ret;
    }
};
```



#### 最后

感谢您的观看！

欢迎大家留言，一起讨论交流。