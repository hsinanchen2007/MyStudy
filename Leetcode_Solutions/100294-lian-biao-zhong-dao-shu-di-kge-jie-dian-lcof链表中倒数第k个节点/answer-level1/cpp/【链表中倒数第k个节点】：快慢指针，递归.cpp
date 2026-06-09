#### 快慢指针

- 定义两个指针，快指针 $fast$， 慢指针 $low$ .
- 让 $fast$ 先向前移动 $k$ 个位置，然后 $low$ 和 $fast$ 再一起向前移动 .
- 当 $fast$ 到达链表尾部，返回 $low$ .



#### 代码

```cpp
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
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
        return low;        
    }
};
```



#### 递归

- 先一直递归到链表尾部，再返回
- 定义位置变量 $pos$ ，每次函数返回时 $pos++$ 
- 当 $pos == k$ 时，说明此时递归函数位于第 $k$ 个结点位置，返回该结点



#### 代码

```cpp
class Solution {
public:
    int pos = 0;
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == NULL) {
            return 0;
        }
        ListNode* ret = getKthFromEnd(head->next, k);
        pos++;
        if (pos == k) {
            return head;
        }
        return ret;    
    }
};
```



#### 最后

感谢您的观看！欢迎大家留言，一起讨论交流。

至此，您已经学会使用快慢指针和递归方法解决此题，如果这篇文章对您有帮助，您可以扫描下方二维码关注我的公众号“小小算法”，感谢您的支持！

![小小算法.png](https://pic.leetcode-cn.com/1776597b2773892787b2a16738cd78feb346c5a5290273bce69275b0b66a0a95-%E5%AE%A3%E4%BC%A0%E5%9B%BE2.png)