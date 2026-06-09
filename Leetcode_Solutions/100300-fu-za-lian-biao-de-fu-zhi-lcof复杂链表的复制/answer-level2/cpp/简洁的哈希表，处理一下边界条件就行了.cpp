### 解题思路
执行用时 :8 ms, 在所有 C++ 提交中击败了98.36% 的用户
内存消耗 :13.6 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hmap; 
        for (Node *curr = head; curr; curr = curr->next){
            hmap[curr] = curr;
        }
        for (auto &el:hmap){
            el.second = new Node(el.first->val);
        }
        for (auto &el:hmap){
            el.second->next = el.first->next ?hmap[el.first->next]:el.first->next;
            el.second->random = el.first->random? hmap[el.first->random]:el.first->random;
        }

        return hmap[head];
    }
};
```