/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

/*

https://leetcode.cn/problems/implement-stack-using-queues/

225. 用队列实现栈
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

实现 MyStack 类：

void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
 

注意：

你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
 

示例：

输入：
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 2, 2, false]

解释：
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // 返回 2
myStack.pop(); // 返回 2
myStack.empty(); // 返回 False
 

提示：

1 <= x <= 9
最多调用100 次 push、pop、top 和 empty
每次调用 pop 和 top 都保证栈不为空
 

进阶：你能否仅用一个队列来实现栈。

通过次数211,102提交次数312,344

*/

// @lc code=start
class MyStack {
public:

    // 2022.7.24, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.md
    /*
       （这里要强调是单向队列）
       
       有的同学可能疑惑这种题目有什么实际工程意义，其实很多算法题目主要是对知识点的考察和教学意义远大于其工程实践的意义，所以面试题也是这样！
       
       刚刚做过栈与队列：我用栈来实现队列怎么样？的同学可能依然想着用一个输入队列，一个输出队列，就可以模拟栈的功能，仔细想一下还真不行！
      
       队列模拟栈，其实一个队列就够了，那么我们先说一说两个队列来实现栈的思路。
       
       队列是先进先出的规则，把一个队列中的数据导入另一个队列中，数据的顺序并没有变，并没有变成先进后出的顺序。
       
       所以用栈实现队列， 和用队列实现栈的思路还是不一样的，这取决于这两个数据结构的性质。
      
       但是依然还是要用两个队列来模拟栈，只不过没有输入和输出的关系，而是另一个队列完全用又来备份的！
      
       如下面动画所示，用两个队列que1和que2实现队列的功能，que2其实完全就是一个备份的作用，把que1最后面的元素以外的元素都备份到que2，
       然后弹出最后面的元素，再把其他元素从que2导回que1。
      
       模拟的队列执行语句如下：
       queue.push(1);        
       queue.push(2);        
       queue.pop();      注意弹出的操作       
       queue.push(3);        
       queue.push(4);       
       queue.pop();     注意弹出的操作    
       queue.pop();    
       queue.pop();    
       queue.empty();    
       225.用队列实现栈
    */

    queue<int> que1;
    queue<int> que2; // 辅助队列，用来备份

    MyStack() {

    }
    
    void push1(int x) {
        que1.push(x);
    }
    
    int pop1() {
        int size = que1.size();
        size--;
        while (size--) { // 将que1 导入que2，但要留下最后一个元素
            que2.push(que1.front());
            que1.pop();
        }

        int result = que1.front(); // 留下的最后一个元素就是要返回的值
        que1.pop();
        que1 = que2;            // 再将que2赋值给que1
        while (!que2.empty()) { // 清空que2
            que2.pop();
        }
        return result;
    }
    
    int top1() {
        return que1.back();
    }
    
    bool empty1() {
        return que1.empty();
    }


    // 优化
    // 其实这道题目就是用一个队列就够了。
    // 一个队列在模拟栈弹出元素的时候只要将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部，此时在去弹出元素就是栈的顺序了。

    queue<int> que;

    /** Initialize your data structure here. */
    // Commeted out by Hsinan as this is class constructor defined in early code above
    //MyStack() {
    //
    //}

    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = que.size();
        size--;
        while (size--) { // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
            que.push(que.front());
            que.pop();
        }
        int result = que.front(); // 此时弹出的元素顺序就是栈的顺序了
        que.pop();
        return result;
    }

    /** Get the top element. */
    int top() {
        return que.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


/************************************************************************************************************/
/************************************************************************************************************/


// 2022.8.15, not in top list

// @lc code=end

