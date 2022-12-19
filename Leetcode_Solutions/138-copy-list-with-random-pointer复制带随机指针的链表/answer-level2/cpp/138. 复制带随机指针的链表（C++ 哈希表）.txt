# 138. 复制带随机指针的链表

**思路:**

- 对于传来的原始数据链表进行两次遍历：
- 第一次遍历:
    1. 根据原始数据链表创建相应个数和值得结果链表。
    2. 只根据传入链表的连接顺序连接结果链表所有结点的next指针，并赋val值。
    3. 利用map数据结构map<Node*,Node*>，将原始链表与结果链表每个结点一一对应进行保存。
- 第二次遍历：
    1. 指针重新回到原始数据链表头部开始遍历原始链表。
    2. 如果遍历到的这个结点有random指针，从map中找到该原始链表random指针指向结点，相对应的结果链表的结点值。赋值结果链表的random指针。

**代码实现：**
```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
		Node rsthead(0,NULL,NULL);
		Node* last = &rsthead;
		Node* src = head;
		
		map<Node*,Node*> m_addrMap;
		
        while(src){
			Node* temp = new Node(src->val,NULL,NULL);
			last->next = temp;
			m_addrMap.insert(pair<Node*,Node*>(src,temp));
			last = temp;
			src = src->next;
		}
		
		Node* dst = rsthead.next;
		map<Node*,Node*>::iterator iter;
		while(head){
			if(head->random != NULL){
				iter = m_addrMap.find(head->random);
				dst->random = iter->second;
			}
			dst = dst->next;
			head = head->next;
		}
		
		return rsthead.next;
    }
};
```

