### 解题思路
先喷一下直接用stl stack实现的sb 或者 其他语言也是直接用现成容器的sb，题目让你自己设计栈，你tm就封装一下，还写那么麻烦，给爷看呆了都。
这里用链表来实现栈，通俗易懂，代码量少，直接看注释即可。

### 代码

```cpp
class MinStack {
private:
    struct Node{
        int val;   // 当前节点的值
        int min;   // 当前以此节点为栈顶的栈内最小元素的值
        Node *next;   // 下一个节点

        Node(int x, int y) : val(x), min(y), next(nullptr) {}
    };
    Node *head;   // 声明头节点

public:
    /** initialize your data structure here. */
    MinStack() {
        head = nullptr;   // 初始化头节点
    }

    void push(int x) {
        // 若栈空，则申请新节点空间并赋予头节点（相当于当前节点入栈）
        if(head == NULL){
            head = new Node(x, x);
        }
        // 若栈非空，则更新新节点的栈内元素最小值后，将新节点插入栈顶，最后更新头节点
        else{
            int tmp = x < head->min ? x : head->min;
            Node *cur = new Node(x, tmp);
            cur->next = head;
            head = cur;
        }
    }

    void pop() {
        // 让头节点指向自身的下一个节点即可
        // 不用管出栈之后的最小值变化，即使当前出栈元素就是最小值也无妨，
        // 因为每个节点的 min 值记录的都是栈底到此节点的元素最小值
        head = head->next;
    }

    int top() {
        // 直接返回头节点 val 值即可，头节点永远指向栈顶
        return head->val;
    }

    int getMin() {
        // 直接返回头节点 min 值即可，头节点的 min 值永远是栈内所有元素的最小值
        return head->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```