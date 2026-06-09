#include <vector>
#include <algorithm>

bool cmp(const ListNode *a, const ListNode *b){
     return a -> val < b -> val;
 }
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::vector<ListNode *> node_vec;
        for(int i = 0; i < lists.size(); i++){//遍历k个链表
            ListNode *head = lists[i];//取出每个链表的头节点
            while(head){//将每个链表的节点放入vector
                node_vec.push_back(head);
                head = head -> next;
            }
        }
        if(node_vec.size() == 0){
            return NULL;
        }
        std::sort(node_vec.begin(), node_vec.end(), cmp);//不能默认，必须指定比较的是数值域
        for(int i = 1; i < node_vec.size(); i++){//连接链表
            node_vec[i-1] -> next = node_vec[i];
        }
        node_vec[node_vec.size()-1] -> next = NULL;
        return node_vec[0];
    }
};
