### 解题思路
边界判定值得好好思考：
    1，判断输入是否非空
    2，每当设及到->next时候，都要考虑是否要判断下一节点为空的情况
删除特定值分为两种情况：
    1，删除值在firstNode，其中还要考虑可能开头有几个节点连续等于特定值的情况
    2，删除值在链条的中间或者末尾位置

### 代码

```cpp
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return head;
        while (head->val == val) {            
            head = head->next;
            if (head == nullptr)  //这里要判断下一个节点为空的情况
                return head;
        }
            
        ListNode *copy = head;
        while (copy->next != nullptr) {
            if (copy->next->val == val)
                copy->next = copy->next->next;
            else
                copy = copy->next;
        }
        return head;
    }
};
```