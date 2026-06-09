后一个节点直接覆盖前一个节点，采用深拷贝思想
class Solution {
public:
void deleteNode(ListNode* node) {
        
*node = *(node -> next); }
};