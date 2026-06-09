题解里的大神[用图形说明解法]([https://leetcode-cn.com/problems/copy-list-with-random-pointer/solution/yong-tu-xing-shuo-ming-jie-fa-by-commonheart])已经说的很详细了，不再赘述。

note: 初始化函数要尽量赋值，否则可能出错
```
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return nullptr;
        Node *cohead = head;
        while(cohead){
            Node *copy = new Node(cohead -> val, cohead -> next, nullptr); //初始化要赋值，要不会出错
            Node *temp = cohead -> next;
            cohead -> next = copy;
            cohead = temp;
        }
        cohead = head;
        while(cohead){
            if(cohead -> random)    cohead -> next ->random = cohead -> random -> next;
            cohead = cohead -> next -> next;
        }
        cohead = head;
        Node *ans = head -> next;
        while(cohead -> next){
            Node *temp = cohead -> next;
            cohead -> next = cohead -> next -> next;
            cohead = temp;
        }
        return ans;
    }
};
```
