### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了98.67% 的用户
内存消耗 :8.9 MB, 在所有 C++ 提交中击败了46.74%的用户

### 代码

```cpp
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
	int GetListNodeSize(ListNode* head){
		if(!head) return 0;
		int size = 0;
		while(head){
			size++;
			head = head->next;
		}
		return size;
	}
	ListNode* GetListNodeTail(ListNode* head){
		if(!head) return NULL;
		while(head->next){
			head = head->next;
		}
		return head;
	}
	//for debug
	void TraverseListNode(const string& list_name, ListNode* head){
		cout << endl << list_name << ": ";
		if(!head) return;
		while(head){
			cout << head->val << " ";
			head = head->next;
		}
	}
//	61. 旋转链表
    ListNode* rotateRight(ListNode* head, int k) {
    	int size = GetListNodeSize(head);
        if(!size) return NULL;
        if(size == 1) return head;
    	int k_in_fact = k % size;
    	ListNode* head_bak = head;
    	for(int i=1; i<size-k_in_fact; ++i){
    		head_bak = head_bak->next;
    	}
    	ListNode* tail_fraction = head_bak->next;
    	ListNode* tail_fraction_bak = tail_fraction;
//    	TraverseListNode("tail_fraction_bak", tail_fraction_bak);
    	tail_fraction_bak = GetListNodeTail(tail_fraction_bak);
//    	TraverseListNode("GetListNodeTail(tail_fraction_bak)", tail_fraction_bak);
//    	TraverseListNode("head", head);

    	head_bak->next = NULL;
//    	TraverseListNode("After head_bak cut tail, head", head);
    	if(tail_fraction_bak){
    		tail_fraction_bak->next = head;
            head = tail_fraction;
    	}        

//    	TraverseListNode("Final head", head);

    	return head;
    }
};
```