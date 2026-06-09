### 解题思路
首先遍历链表，然后将遍历的结果放到vector中，最后将vector反转。

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
    vector<int> reversePrint(ListNode* head) {
        vector<int> link2Vec;
        // if(head == nullptr) return ;    // 先判断链表是否为空

        ListNode* pNode = head;
        
        while(pNode){
            // 当前节点不为空
            link2Vec.push_back(pNode->val);
            pNode = pNode->next;
        }

        int len = link2Vec.size();
        // 反转vector
        for(int i = 0; i < len - 1 - i; ++i){
            int temp = link2Vec[i];
            link2Vec[i] = link2Vec[len - 1 -i];
            link2Vec[len - 1 - i] = temp;
        }

        return link2Vec;
    }
};
```
### 解题思路
通过辅助栈

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
    vector<int> reversePrint(ListNode* head) {
        stack<int> link2Stack;
        vector<int> link2Vec;
        ListNode* pNode = head;
        
        while(pNode){
            // 当前节点不为空
            link2Stack.push(pNode->val);
            pNode = pNode->next;
        }
        while(!link2Stack.empty()){
            link2Vec.push_back(link2Stack.top());   // 返回栈顶元素到vector
            link2Stack.pop();   // 删除栈顶元素
        }

        return link2Vec;
    }
};
```