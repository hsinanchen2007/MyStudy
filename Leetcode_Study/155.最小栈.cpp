/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

/*

https://leetcode.cn/problems/min-stack/

155. 最小栈

中等
1.5K
company
亚马逊
company
彭博 Bloomberg
company
微软 Microsoft
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:

MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。
 

示例 1:

输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
 

提示：

-231 <= val <= 231 - 1
pop、top 和 getMin 操作总是在 非空栈 上调用
push, pop, top, and getMin最多被调用 3 * 104 次

*/

// @lc code=start
class MinStack100 {
public:
    MinStack100() {
        
    }
    
    void push(int val) {
        myStack.push(val);
        if (helper.empty() || helper.top().first > val) {
            helper.push({val, 1});
        } else if (helper.top().first == val) {
            helper.top().second++;
        }
    }
    
    void pop() {
        if (myStack.top() == helper.top().first) {
            helper.top().second--;
            if (helper.top().second == 0) {
                helper.pop();
            }
        }
        myStack.pop();
    }
    
    int top() {
        return myStack.top();
    }
    
    int getMin() {
        return helper.top().first;
    }

private:
    stack<int> myStack;
    stack<std::pair<int, int>> helper;
};


class MinStack {
public:
    // 2023.1.21 by Hsin-An, both stacks keep same size, one is normal, another
    // stack will track the minimum value within all elements in normal stack
    // at that position
    MinStack() {
        
    }
    
    void push(int val) {
        if ((minStack.size() == 0) || 
            (minStack.size() > 0 && val <= minStack.top())) {
            minStack.push(val);
        } else if (minStack.size() > 0 && val > minStack.top()) {
            int tmp = minStack.top();
            minStack.push(tmp);
        } 
        myStack.push(val);
    }
    
    void pop() {
        myStack.pop();
        minStack.pop();
    }
    
    int top() {
        return myStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }

private:
    stack<int> myStack;
    stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

