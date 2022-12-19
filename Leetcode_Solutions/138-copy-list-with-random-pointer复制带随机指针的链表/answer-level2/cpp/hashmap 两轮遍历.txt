
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
Node* copyRandomList(Node* head) {
	if (!head)return NULL;
	unordered_map<Node*, Node*> map;
	Node* first_node = NULL;
	while (head != NULL) {//第一轮遍历，将所有新节点 以旧节点为key存入hashmap;
		Node* temp_node = new Node(head->val);
		temp_node->next = head->next;
		temp_node->random = head->random;
		map[head] = temp_node;
		head = head->next;
		if (!first_node) first_node = temp_node;//记录首节点
	}
	head = first_node;
	while(head != NULL){//第二轮遍历用新地址代替就地址
		head->random = map[head->random];
		head->next = map[head->next];
		head = head->next;
	}
	return first_node;
}
};
```