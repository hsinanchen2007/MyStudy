### 解题思路
先回宿后插入

### 代码

```cpp
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return NULL;
        return traceback(head); 
    }
    ListNode* traceback(ListNode* node){ //深度优先搜索
        if(!node->next) return node;
        else node->next=traceback(node->next); //先深挖到最后一个
        // 回溯，为了从后向前排序，这样回溯时，当前节点的后面都是排序好了的
        if(node->val > node->next->val){ //判断是否需要交换，
            ListNode* temp=node->next;
            node->next = node->next->next;
            temp->next = insert(node); //回溯了以后就，向后插入，
            return temp; //
        }else{
            return node;
        }
    }
    ListNode* insert(ListNode* node){ //向后插入，后面的都是排列好顺序的。
        if(!node->next) return node;
        if(node->val > node->next->val){
            ListNode* temp=node->next;
            node->next= node->next->next;
            temp->next=insert(node);
            return temp;
        }else
            return node;
    }
};
```