### 解题思路
递归法归并法

![image.png](https://pic.leetcode-cn.com/a3a1250674ffa0473f9ffea7ebff6da522a0c7a942b2265c6037ec14eb72dae4-image.png)
![image.png](https://pic.leetcode-cn.com/d5a227716ce8045ffd8bae04d13a77192840cd46efb9ec2e11665dcd9f6c3965-image.png)

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL){return l2;}
        if(l2==NULL){return l1;}
        //判断 l1 和 l2 头结点哪个更小，然后较小结点的 next 指针指向其余结点
        //每次返回合并好的头节点
        if(l1->val<l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }else{
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};
```