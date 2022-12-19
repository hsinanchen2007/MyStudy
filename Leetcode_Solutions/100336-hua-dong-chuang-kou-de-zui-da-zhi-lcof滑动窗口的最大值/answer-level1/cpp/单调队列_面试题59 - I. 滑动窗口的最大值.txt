### 解题思路
学习大佬的思想：[单调队列解题详解](https://leetcode-cn.com/problems/sliding-window-maximum/solution/dan-diao-dui-lie-by-labuladong/)

    /*
     * 方法1 单调队列 O(n)
     *
     * 窗口大小为k的滑动窗口，每次计算窗口内的最大值，可以使用单调队列的方法。
     * 单调队列保持队列中的值从大到小排列，将滑动窗口中的值入队后，
     * 队首元素即为该滑动窗口的最大值。而单调队列入队、出队和取最大值的平均时间为O(1),
     * 所以遍历整个数组，计算每个滑动窗口的最大值的时间复杂度为O(n)。
     * */
### 代码

```cpp
// 实现单调队列 O(1)
class MonotonicQueue {
private:
    std::deque<int> data;
public:
    // 入队函数
    void push(int n) {
        // 如果队尾元素小于当前元素，
        // 则将队尾元素出队
        while (!data.empty() && data.back() < n) {
            data.pop_back();
        }
        // 入队当前元素，
        // 则队列中元素仍然保持递减
        data.push_back(n);
    }

    // 取队列最大元素，即队首
    int max() {
        return data.front();
    }

    // 弹出队首等于n的元素
    void pop(int n) {
        if (!data.empty() && data.front() == n) {
            data.pop_front();
        }
    }
};

std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
    if (nums.empty()) {
        return {};
    }

    // 定义存储滑动窗口内值的单调队列
    MonotonicQueue window;

    std::vector<int> ans;

    // 遍历数组中的数
    for (int i = 0; i < nums.size(); i++) {
        // 将该滑动窗口内的前k-1个数压入队列
        // 队列始终保持从大到小递减
        if (i < k - 1) {
            window.push(nums[i]);
        } else {
            // 窗口向前滑动，压入第k个数
            window.push(nums[i]);
            // 取队列中的最大数为该滑动窗口最大值
            ans.push_back(window.max());
            // 因为窗口向右滑动，弹出窗口的第一个数
            window.pop(nums[i - k + 1]);
        }
    }

    return ans;
}
```

### 另一种实现 双端队列
    /*
     * 原理同方法1 使用双端队列存储滑动窗口中数字的索引，同样实现单调队列的形式。
     *
     * 遍历数组时，将窗口逐渐右移：
     * 1. 当队列不为空时，如果当前队首索引不在窗口内时，将队首从队列中出队；
     * 2. 当队列不为空时，如果队尾索引对应的值小于当前值时，将队尾索引出队，
     *    直到找到索引对应值大于等于当前值，则将当前值对应的索引入队，保证双端队列是单调递减的；
     * 3. 因为双端队列索引对应的值是递减的，则队首索引对应的值即为该滑动窗口的最大值，返回该值。
     * */

### 代码

```cpp
std::vector<int> maxSlidingWindow2(std::vector<int> &nums, int k) {
    if (nums.empty()) {
        return {};
    }

    // 定义双端队列
    std::deque<int> winDeq;

    // 将第一个窗口的值对应的索引按照单调队列入队
    for (int i = 0; i < k; i++) {
        while (!winDeq.empty() && nums[i] > nums[winDeq.back()]) {
            winDeq.pop_back();
        }
        winDeq.push_back(i);
    }

    std::vector<int> ans;
    // 将第一个窗口的最大值存入结果数组中
    ans.push_back(nums[winDeq.front()]);

    // 此后将滑动窗口右移，从第k个数开始
    for (int i = k; i < nums.size(); i++) {
        // 如果队首索引不在窗口内时，
        if (i - winDeq.front() == k) {
            // 则将队首出队
            winDeq.pop_front();
        }
        // 将下一个窗口的数对应的索引入队
        while (!winDeq.empty() && nums[i] > nums[winDeq.back()]) {
            winDeq.pop_back();
        }
        winDeq.push_back(i);

        // 每次返回队列的队首
        ans.push_back(nums[winDeq.front()]);
    }
    return ans;
}
```