### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL){return head;}
		vector<ListNode*> v;
		ListNode *p = head;
		while (head!=NULL) {
			v.push_back(head);
			head = head->next;
		}
		for (int i = 0; i < v.size() - 1;i=i+2) {
			v[i + 1]->next = v[i];
			v[i]->next = NULL;
		}

		for (int i = 0; i < v.size();i=i+2) {
			if ((i+3)<v.size()) {
				v[i]->next = v[i + 3];
			}
		}
        if(v.size()%2!=0){
            v[v.size()-3]->next=v[v.size()-1];

        }

		return v[1];
	}
};
```