执行用时4ms，内存小号8.5MB

首先处理特殊情况，如果入参为空则返回空，如果只有一个节点则返回这个节点。对于其他的情况，返回的肯定是节点2的指针。

然后再看交换，交换的规则如图所示：

![shortcut.png](https://pic.leetcode-cn.com/45eff5fa5ddf61a8aa93e16fc688286dc022698bc18b83943d87583f80b78187-QQ%E6%88%AA%E5%9B%BE20200216124646.png)

先不考虑结尾，我们可以以两个节点为步长来进行循环：循环体中**用于遍历的指针head移动到节点3，把节点2的next指向节点1，把节点1的next指向节点4**。

考虑结尾的情况：还剩4个节点时，处理方式和上面一样；剩3个节点时，循环中的节点1的next就得指向节点3；剩两个节点时循环中节点1的next指向空。只剩一个节点、不剩节点时就不需要任何操作了（上一轮循环已经处理好了指向本轮循环的指针，本轮循环中不需要再指向任何节点）。

代码如下：

```cpp
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head) {
            return NULL;
        }
        if (!head->next) {
            return head;
        }
        ListNode *ret = head->next;
        while (head) {
            auto one = head;
            auto two = head->next;
            if (two) {
                head = two->next;
                two->next = one;
                if (head && head->next) {
                    one->next = head->next;
                } else {
                    one->next = head;
                }
            } else {
                head = NULL;
            }
        }
        return ret;
    }
};
```