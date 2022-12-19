# 817. 链表组件

**思路：**

- 利用SET数据结构保存传入vector中的值。
- 遍历传入链表，如果该节点的值域数值在SET中可以被找到，链表组件数加一。然后遍历直到结点为空或某一结点值不为SET中保存过的值。

**代码：**
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
    	set<int> m_set;
        for( int i = 0; i < G.size(); ++i ){
        	m_set.insert(G[i]);
        }

        int Comnum = 0;
        while( head != NULL ){
        	if( m_set.find(head->val) != m_set.end() ){
        		Comnum++;
        		while( m_set.find(head->val) != m_set.end() ){
        			head = head->next;
        			if(!head){
        				break;
        			}
        		}
        	}else{
        		head = head->next;
        	}
        }
        return Comnum;
    }
};
```
