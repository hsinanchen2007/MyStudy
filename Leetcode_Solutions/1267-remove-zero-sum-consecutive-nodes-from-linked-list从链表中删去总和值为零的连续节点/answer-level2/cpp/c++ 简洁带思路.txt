思路：

我们可以考虑如果给的入参不是链表是数组的话，只需要求出前缀和，对于前缀和相同的项，那他们中间的部分即是可以消除掉的，比如以 [1, 2, 3, -3, 4] 为例，其前缀和数组为 [1, 3, 6, 3, 7] ，我们发现有两项均为 3，则 6 和 第二个 3 所对应的原数组中的数字是可以消掉的。换成链表其实也是一样的思路，把第一个 3 的 next 指向第二个 3 的 next 即可

代码实现：

```c++
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // 保存前缀和
        unordered_map<int, ListNode*> prefixSum;
        // 因为头结点也有可能会被消掉，所以这里加一个虚拟节点作为头结点
        ListNode* dummy = new ListNode(0), *p = dummy;
        dummy->next = head;
        
        prefixSum[0] = p;
        int cur = 0, tempCur = 0;
        while (p = p->next) {
            cur += p->val;
            if (prefixSum.find(cur) != prefixSum.end()) {
                ListNode* temp = prefixSum[cur]->next;
                prefixSum[cur]->next = p->next;
                tempCur = cur;
                // 还需要从 map 中删除消除区间的前缀和
                while (temp != p) {
                    tempCur += temp->val;
                    prefixSum.erase(tempCur);
                    temp = temp->next;
                }
                
            } else {
                prefixSum[cur] = p;
            }
        }
        
        return dummy->next;
    }
};
```

更多题解欢迎关注 [Do Leetcode For Fun](https://zhuanlan.zhihu.com/c_1145647496591298560) 专栏~
