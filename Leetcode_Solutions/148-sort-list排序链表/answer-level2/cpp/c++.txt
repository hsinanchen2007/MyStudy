### 解题思路
此处撰写解题思路

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
	ListNode* sortList(ListNode* head) {
		int length = 0;
		ListNode* p = head;
		while (p) {
			p = p->next;
			length++;
		}

		ListNode* ret = new ListNode(0);//返回值
		int fragmentLen = 1;//当前归并长度
        ListNode* overage ;//存放切割后剩下的链表
		while (fragmentLen <= length) {
			overage = ret->next ? ret->next : head;//最开始ret->next为空从head读取，排序后接入ret所以后续从ret->next 读取
            // cout<<"总链表："<<endl;
            // nodeRead(overage);

			p = ret;
			while (overage) {
				ListNode* l1 = overage;
				ListNode* l2 = cutList(l1, fragmentLen);
                overage = cutList(l2, fragmentLen);
                // cout<<"长度:"<<fragmentLen<<endl;
                // cout<<"待合并链表1"<<endl;nodeRead(l1);
                // cout<<"待合并链表2"<<endl;nodeRead(l2);
                ListNode* mergeNode = merge(l1, l2);
                // cout<<"合并链表"<<endl;nodeRead(mergeNode);
				p->next = mergeNode;
				while (p->next) {
					p = p->next;
				}
			}
			fragmentLen *= 2;
		}
		return ret->next;
	}
	

	//返回切断后第二段的首节点
	ListNode* cutList(ListNode* head, int len) {
		while (len > 1 && head) {
			head = head->next;
            len--;
		}
		if (!head) return NULL;
		ListNode* res = head->next;
		head->next = NULL;
		return res;
	}
	ListNode* merge(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(0);
		ListNode* node = head;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				head->next = l1;
				l1 = l1->next;
			}
			else {
				head->next = l2;
				l2 = l2->next;
			}
			head = head->next;
		}
		head->next = l1 ? l1 : l2;
		return node->next;
	}
	
    // void nodeRead(ListNode* head){
    //     ListNode* read = head;
    //     while(read){
    //         cout<<read->val<<" ";
    //         read = read->next;
    //     }
    //     cout<<endl;
    // }
};

```