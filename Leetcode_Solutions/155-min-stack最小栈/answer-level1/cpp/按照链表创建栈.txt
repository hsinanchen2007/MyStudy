```
#include<iostream>
#include<stack>

class MinStack {
public:
	/** initialize your data structure here. */
	typedef struct Node {
		int value;
		int cur;
		Node *next;
		Node(int x) :value(x), cur(x), next(NULL) {}
	}node;  //创建链表节点数据结构

	MinStack() {
		head = new node(NULL);  //用链表指针，头指针的值为空，只为指向下一节点
	}

	void push(int x) {
		node *pre = new node(x);
		if (min >= pre->value) {  //每次和当前最小值比较如果小，则把节点值进站
			min = pre->value;
			mins.push(min);
		}
		pre->cur = mins.top();
		pre->next = head->next;
		head->next = pre;
	}

	void pop() {
		if (head->next->value == head->next->cur) {  //如果最小值出去
			mins.pop();
			if (!mins.empty()) {
                min = mins.top(); //因为先pop()要判断是否栈空，并且min的值需要随之变化
                head->next->cur = mins.top();
            }
			else head->next->cur = NULL;
		}
		head->next = head->next->next;
		if (head->next == nullptr) {
			min = INT_MAX;
		}
	}

	int top() {
		int val;
		val = head->next->value;
		return val;
	}

	int getMin() {
		return head->next->cur;  //取最新插入节点的表示最小值的值，最小值是随着入栈和出站操作更新的
	}
private:
	node *head; //链表头
	int min = INT_MAX;
	std::stack<int>mins;
};

```
由于最小值可能需要按照深度变化，因此又用了一个栈保存最小值！没能完全不用数据结构实现。