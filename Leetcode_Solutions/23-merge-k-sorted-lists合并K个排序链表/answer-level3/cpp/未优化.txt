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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
            找当前最小
        */
        int min_index = -1, minValue = INT_MAX;
        if(lists.empty())return NULL;
        
        ListNode* head = new ListNode(-1);
        ListNode* p = head;

        int len = lists.size();
        while(1){
            //遍历所有组，找组头最小元素
            for(int i = 0 ; i < len ; i++){
                if(lists[i]==NULL)continue;
                if( minValue > lists[i]->val){
                    minValue = lists[i]->val;
                    min_index = i;
                }
            }
            if(min_index == -1){//没有找到最小值，其实就是里面没有值了
                break;
            }  
            //建点，and递推。。
            p->next = new ListNode(minValue);
            p = p->next;
            lists[min_index] = lists[min_index]->next;

            min_index =-1;
            minValue = INT_MAX; //init
        }

        return head->next;
    }
};
```