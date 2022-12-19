### 解题思路
解题思路参考[图解 模拟入栈操作，贪心算法](https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/solution/tan-xin-by-z1m/)

    /*
     * 贪心算法
     *
     * 此题所用贪心法则为：
     * 如果栈顶元素等于popped序列中下一个要pop的值，
     * 则应立即将该值弹出
     *
     * 设置辅助栈来模拟栈的压入和弹出，
     * 对pushed序列遍历并依次压入辅助栈中，
     * 当辅助栈不空且其栈顶与popped序列第一个要弹出的值相等，
     * 则将该栈顶出栈，再判断栈不为空时，
     * 栈顶是否与popped序列第二个要弹出值相等，
     * 相等则弹出，继续上述操作，
     * 不相等时继续遍历pushed序列并压栈
     * */

### 代码

```cpp
bool validateStackSequences(std::vector<int> &pushed, std::vector<int> &popped) {
    if(pushed.size() != popped.size()){
        return false;
    }

    std::stack<int> stk;
    int m = pushed.size();
    int index = 0;

    // 对pushed序列元素遍历
    for(int i = 0; i < m; i++){
        // 将pushed元素依次压入辅助栈
        stk.push(pushed[i]);

        // 当栈不为空且栈顶元素等于popped序列下一个要弹出的元素
        while (!stk.empty() && stk.top() == popped[index]){
            // 立即弹出该元素
            stk.pop();
            // popped索引加1，指向下一个要弹出元素
            index++;
        }
    }

    // 判断栈是否为空，为空则是有效弹出序列
    return stk.empty();
}
```