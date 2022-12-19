```c++
class MaxStack {
public:
    stack<int> elStack;
    stack<int> maxStack;

    /** initialize your data structure here. */
    MaxStack() {

    }

    void push(int x) {
        elStack.push(x);
        if (maxStack.empty() || x >= maxStack.top()) {
            maxStack.push(x);
        }
    }

    int pop() {
        int num = elStack.top();
        elStack.pop();
        if (num == maxStack.top()) {
            maxStack.pop();
        }
        return num;
    }

    int top() {
        return elStack.top();
    }

    int peekMax() {
        return maxStack.top();
    }

    int popMax() {
        int maxNum = maxStack.top();
        maxStack.pop();
        stack<int> tmp;
        while(elStack.top() != maxNum) {
            tmp.push(elStack.top());
            elStack.pop();
        }
        elStack.pop();
        while(!tmp.empty()) {
            push(tmp.top());
            tmp.pop();
        }
        return maxNum;
    }
};