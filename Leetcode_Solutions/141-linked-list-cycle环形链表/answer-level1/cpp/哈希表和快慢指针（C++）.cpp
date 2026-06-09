本题我使用链表题目最常用的两种方法：哈希表和快慢指针

## 哈希表

储存结点，发现相同的即为有环，时间复杂度O(n),空间复杂度O(n)

```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set <ListNode*> hash;
        while (head){
            if (hash.find(head) != hash.end()){
                return true;
            }
            else{
                hash.insert(head);
                head = head->next;
            }
        }
        return false;
    }
};

```

## 快慢指针

有环必然相遇，可以当做结论。

```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next){
                slow = slow->next;
                fast = fast->next->next;
                if (fast == slow) {
                    return true;
                }
            }
        return false;
    }
};
```
github pages：https://aiaimuti.github.io/ 里面有很多关于C++的总结

