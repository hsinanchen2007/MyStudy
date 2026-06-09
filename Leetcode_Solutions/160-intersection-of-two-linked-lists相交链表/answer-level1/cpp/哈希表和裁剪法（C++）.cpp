## 哈希表

先将headA所有放入哈希表，再遍历headB，找到一个已有的节点返回

```python []
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        hash_set = set()
        while headA:
            hash_set.add(headA)
            headA = headA.next
        while headB:
            if headB in hash_set:
                return headB
            else:
                headB = headB.next
        return None
```
```C++ []
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set <ListNode*> hash;
        while (headA){
            hash.insert(headA);
            headA = headA->next;
        }
        while (headB){
            if (hash.find(headB) != hash.end()){
                return headB;
            }
            else {
                headB = headB->next;
            }
        }
        return NULL;
    }
};
```


## 裁剪法

相交必定相交的部分长度相等，减去长链表的长部分，然后同时移动找到相交节点。

```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode* countA = headA;
        ListNode* countB = headB;
        int A = 0;
        int B = 0;
        while (countA){
            A++;
            countA = countA->next;
        }
        while (countB){
            B++;
            countB = countB->next;
        }
        while (A < B){
            headB = headB->next;
            B--;
        }
        while (A > B){
            headA = headA->next;
            A--;
        }
        while (A == B){
            if (headA == headB){
                return headA;
            }
            else{
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL; 
    }
};
```
github pages：https://aiaimuti.github.io/ 里面有很多关于C++的总结


