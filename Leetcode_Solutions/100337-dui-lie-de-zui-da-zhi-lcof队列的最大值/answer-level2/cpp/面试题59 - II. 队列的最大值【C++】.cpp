### 解题思路

这个题是参考Leetcode的官方题解做的，一开始都没太明白题目意思~

其实 `push_back` 和 `pop_front` 都可以直接用队列的 `pop()` 函数和 `front()` 函数，没有难度，但是 `max_value` 需要考虑的就不一样了，主要是因为题目给了要求时间复杂度是O(1)，也就是说不能用遍历整个队列的方法来找最大值。

题解中用到了**双端队列**，而双端队列的作用就是查找最大值，并且它的巧妙之处在于，双端队列的队首元素 `d.front()` 始终是队列 `q` 中的最大元素。代码中用到的几个关于双端队列的函数如下：

- back()：获取队列的最后一个元素；
- empty()：判断队列空否，空则返回true；
- push_back()：在队列末端插入元素；
- pop_back()：从队列末端弹出队尾元素；
- pop_front()：从队列前端弹出队首元素。

定义一个 `queue<int>` 队列，主要用于元素的入队与出队操作。

在元素入队的函数中，如果双端队列 d 为空或者入队的元素小于 d 的队尾元素，则分别将该元素插入到 d 和 q 的队尾；如果双端队列 d 非空并且入队元素大于 d 的队尾元素，则将 d 的队尾元素逐个弹出，直到 d 的队尾元素大于入队元素或者 d 空，然后将该元素插入到 d 和 q 的队尾。

在队列 q 的出对函数中，需要注意对双端队列 d 的操作，不然可能会造成 q 中已将最大元素删除，但 d 没有进行任何操作，就会导致获取最大值的时候获取到已经删除的不存在于队列中的元素的值。所以需要在 q 和 d 的队首元素相同的情况下，同步删除 d 的队首元素。以保证 d.front() 仍然是队列 q 中剩余元素的最大值。

### 代码

```cpp
class MaxQueue {
private:
    queue<int> q;//队列
    deque<int> d;//双端队列，用于求最大值
public:
    MaxQueue() {}

    int max_value() {
        //d为空也就意味着q为空，因为只要q中有元素，那d.front()就一定是队列q中元素的最大值
        if (d.empty())
            return -1;
        return d.front();
    }

    void push_back(int value) {
        //d要保持单调递减，即为了保持d.front()是最大的元素
        while (!d.empty() && d.back() < value)
        {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);//原始队列
    }

    int pop_front() {
        if (q.empty())
            return -1;
        if (q.front() == d.front())
            d.pop_front();
        int ans = q.front();//获取返回值
        q.pop();//弹出队首元素
        return ans;//返回队首元素的值
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```