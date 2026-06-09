# 430. 扁平化多级双向链表
每次遍历一层时与遍历下一层做的操作一样，用递归方法。
```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
	Node* Cicle(Node* head){
		//记录上层有child结点的下一个结点信息
		Node* parent_next = head->next;
		//上层有child结点与该层第一个节点连接
		Node* temp = head->child;
		head->next = temp;
		temp->prev = head;
		head->child = NULL;	//上层有child结点的child指针赋值为NULL
		
		//遍历该层节点
		Node* m_step;	
		while( temp != NULL ){	//节点为空返回
			m_step = temp;		//记录遍历的当前节点
			if( temp->child != NULL ){	//有child节点 进行下层递归递归
				m_step = Cicle(temp);	//递归返回下层连接后的尾结点
			}
			temp = m_step->next;		//指针后移
		}
		
		//该层第一个节点连接与上层有child结点的下一个结点连接
		m_step->next = parent_next;
		if(parent_next){	//上层下一个节点不为空
			parent_next->prev = m_step;
		}
		return m_step;
	}
	
    Node* flatten(Node* head) {
		if(!head)  return head;
		//生成头结点
        Node prehead(0,NULL,NULL,head);
		//递归开始
		Node* tail = Cicle(&prehead);
		//返回节点的第一个节点的prev设为NULL
		prehead.next->prev = NULL;
		return prehead.next;
    }
};
```
