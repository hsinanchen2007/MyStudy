### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/daf772634ab58f30780818cddd6a9b8b68fec4e9eb2f1ba1665bc8e5d7d7049c-image.png)

把每一个节点指针，全部放在vector中（类似数组），然后返回数组的中间哪一个就行
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
    ListNode* middleNode(ListNode* head) {
        vector<ListNode *> res;
        while(head!=NULL){
            res.push_back(head);
            head=head->next;
        }
        return res[res.size()/2];
    }
};
```