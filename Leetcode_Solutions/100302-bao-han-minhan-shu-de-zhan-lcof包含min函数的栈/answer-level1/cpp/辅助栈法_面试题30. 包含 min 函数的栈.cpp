### 解题思路

    /*
     * 辅助栈法
     * 
     * 一开始想到设置成员变量来存储压入栈的最小值，
     * 但当该最小值弹出后，最小值就需要更新，
     * 所以此方法不完善，遂想到使用一个辅助栈来存储历来的最小值，
     * 即每压入一个数，就将该次的最小值压入辅助栈，
     * 没弹出一个值，如果该值为最小值，辅助栈就弹出栈顶，
     * 所以能够保持辅助栈的栈顶必为最小值。
     * */

### 代码

```cpp
    std::vector<int> stk;
    std::vector<int> auxStk;

MinStack() : stk({}), auxStk({}) {}

void push(int x) {
    if (auxStk.empty() || x < auxStk.back()) {
        auxStk.push_back(x);
    } else {
        auxStk.push_back(auxStk.back());
    }

    stk.push_back(x);
}

void pop() {
    assert(auxStk.size() > 0 && stk.size() > 0);

    auxStk.pop_back();
    stk.pop_back();
}

int top() {
    assert(auxStk.size() > 0 && stk.size() > 0);

    return stk.back();;
}

int min() {
    assert(auxStk.size() > 0 && stk.size() > 0);

    return auxStk.back();
}

```