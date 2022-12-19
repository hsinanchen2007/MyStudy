### 解题思路
相遇问题（快慢指针），存在问题（哈希，set）
map中使用的参数为指针型
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
class Solution {  //典型的快慢指针问题，如果不是环形，他们永远不会相遇，环形的话才会相遇。
public:   //当然map,set也可以，也是使用count()查找。
    bool hasCycle(ListNode *head) {
        //快慢指针解法
        if(head==NULL) return false;
        ListNode *fast=head;
        ListNode *low=head;
        while(fast->next&&fast->next->next){//注意：这里的条件：fast->next!=NULL&&fast->next->next!=NULL ,low在fast后面不需要作为条件判断    
            fast=fast->next->next;
            low=low->next;
            if(fast==low) return true;
        }
        return false;


        /*哈希做法，set做法
        unordered_map<ListNode*,int>maps;
        ListNode *root=head;
        while(root){
            if(maps.count(root)) return true;
            else maps[root]++;
            root=root->next;
        }
        return false;
        */
    }
};
```