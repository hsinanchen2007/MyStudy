### 解题思路 单调双端队列
    /*
     * 单调双端队列
     *
     * 使用双端队列实现一个单调队列，使队列中的数始终保持递减，则双端队列的队首元素始终为最大值。
     * 同时使用普通队列存储输入的数，当对普通队列中的元素做出队操作时，
     * 需要考虑普通队列的队首元素是否与双端队列的队首元素相等，如果相等，则双端队列的队首元素也要出队，
     * 这样才能始终保证双端队列的队首是当前普通队列中所有元素的最大值。
     * */

### 代码

```cpp
MaxQueue::MaxQueue() {}

// 取双端队列队首为当前普通队列中的最大值
int max_value() {
    if (deq.empty()) {
        return -1;
    }

    return deq.front();
}

// 入队操作
void push_back(int value) {
    // 保持双端队列中的队首元素为普通队列所有元素的最大值
    while (!deq.empty() && deq.back() < value) {
        deq.pop_back();
    }
    // 双端队列入队
    deq.push_back(value);

    // 普通队列正常入队
    que.push(value);
}

// 出队操作
int pop_front() {
    if (que.empty()) {
        return -1;
    }

    // 如果当前要出队的队首元素，
    // 普通队首等于双端队首，
    // 则两队列队首都需要出队
    int ans = que.front();
    if (ans == deq.front()) {
        deq.pop_front();
    }
    que.pop();

    return ans;
}
```