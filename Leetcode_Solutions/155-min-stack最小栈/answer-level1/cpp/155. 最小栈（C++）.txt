# 155. 最小栈（C++）
```
class MinStack {
public:
    /** initialize your data structure here. */
	typedef struct Node{
		int val;
		Node *next;
	}Node;
	
	Node *head;
	
    MinStack() {
		head = NULL;
    }
    
    void push(int x) {
		Node *temp = new Node;
		temp->val = x;
		temp->next = head;
		head = temp;
    }
    
    void pop() {
		Node *temp = head;
        head = head->next;
		delete temp;
    }
    
    int top() {
        if(head){
			return head->val;
		}
		return 0;
    }
	
    int getMin() {
		if(head == NULL){
			return 0;
		}
		Node *temp = head;
		int min = temp->val;

		while( temp!=NULL ){
			if( temp->val < min ){
				min = temp->val;
			}
			temp = temp->next;
		}
		return min;
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
