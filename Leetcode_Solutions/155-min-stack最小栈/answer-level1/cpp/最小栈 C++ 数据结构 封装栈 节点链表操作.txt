### 解题思路
此处撰写解题思路

### 代码

```cpp
class MinStack {
public:
    
    // 链表节点
    struct Node {
        int val;
		int min;
		Node *next;
        Node(int _val, Node *_next = NULL) : val(_val), min(val), next(_next) {}
	};
    // 头节点
	Node *head;
    
    /** initialize your data structure here. */
    MinStack() {
        // 初始化栈的头节点，头节点的next将指向栈顶元素。
        head = new Node(0);
    }
    
    // 将元素 x 推入栈中
    void push(int x) {
        // 新节点的next会指向栈顶节点，成为新的栈顶
        Node *tmp = new Node(x, head->next);
        // 如果头节点有后继节点 而且 x比头节点的后继节点的min大
		if (head->next && x > head->next->min) {
            // min保存至今的最小值
			tmp->min = head->next->min;
		}
        // 头节点的next指针，每次都指向新push进来的这个节点
		head->next = tmp;
    }
    
    // 删除栈顶的元素
    void pop() {
        // tmp指向头节点的后继节点，也就是当前的栈顶元素
        Node *tmp = head->next;
        // 栈顶元素存在
		if (tmp) {
            // 头节点的next指向栈顶元素的next，然后删除栈顶元素
			head->next = tmp->next;
			delete tmp;
		}
    }
    
    // 获取栈顶元素
    int top() {
        int top = 0;
        // 栈顶元素存在
		if (head->next) {
            // 获取栈顶元素的val
			top = head->next->val;
		}
		return top;
    }
    
    // 检索栈中的最小元素
    int getMin() {
        int min = 0;
        // 栈顶元素存在
		if (head->next) {
            // 获取栈顶元素的min，栈顶元素的min保存的就是栈中的最小值
			min = head->next->min;
		}
		return min;
    }
};



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinStack {
public:
    struct Node {
        int val;
		int min;
		Node *next;
        Node(int _val, Node *_next = NULL) : val(_val), min(val), next(_next) {}
	};
	Node *head;
    
    MinStack() {
        head = new Node(0);
    }
    
    void push(int x) {
        Node *tmp = new Node(x, head->next);
		if (head->next && x > head->next->min) {
			tmp->min = head->next->min;
		}
		head->next = tmp;
    }
    
    void pop() {
        Node *tmp = head->next;
		if (tmp) {
			head->next = tmp->next;
			delete tmp;
		}
    }
    
    int top() {
        int top = 0;
		if (head->next) {
			top = head->next->val;
		}
		return top;
    }
    
    int getMin() {
        int min = 0;
		if (head->next) {
			min = head->next->min;
		}
		return min;
    }
};

int main() {
    // C++里面new一个类的时候返回的是一个新创建的类的指针
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << endl;
    minStack->pop();
    cout << minStack->top() << endl;
    cout << minStack->getMin() << endl;
}


```