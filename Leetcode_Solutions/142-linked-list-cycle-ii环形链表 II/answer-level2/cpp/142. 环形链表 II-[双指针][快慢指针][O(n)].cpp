经典老题了。

环入口怎么找呢？给一个直观的推导，我们不需要太多的数学工具，只需要一些经验即可。

- 事实：如果 `slow` 走了 `k` 步和 `fast` 相遇，则 `fast` 一定是走了 `2k` 步。


条件：如果在 `slow` 走了 `k` 步的情况下，再来一个 `new_slow` 指针从头开始走。

- 推论一：基于上面的事实，可以推出 `slow` 和 `new_slow` 再走 `k` 步，`slow` 一定也会和 `new_slow` 相遇。（因为这时 `slow` 走了 `2k` 步，`new_slow` 走了 `k` 步，这和事实中的情况一模一样，只是指针身份换了一下）。
- 推论二：基于推论一，又因为 `slow` 和 `new_slow` 速度一致，可以得知，`slow` 和 `new_slow` 一定会首先在环入口相遇。

有同学对推论二还是很迷惑，怎么就能得知一定在环入口相遇。解释一下，推论一你肯定没有问题，假设推论一中，`slow` 和 `new_slow` 在位置 `x` 相遇，由于它们速度一样，那它们也一定会在 `x-1` 的位置相遇，也会在 `x-2, x-3, ...`，你可以这样反推出来，它们一定会在某个位置第一次相遇，那个位置就是环入口。


```cpp
ListNode *detectCycle(ListNode *head) {
    if (!head) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    
    // 看下奇数节点和偶数节点有啥不同
    // @->@->@->@->@->$
    //       ^     ^
    // @->@->@->@->@->@->$
    //          ^        ^
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    
    if (!fast || !fast->next) return nullptr;
    
    fast = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}
```
