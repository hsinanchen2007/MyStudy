### 解题思路
参考用户[@philhsu](/u/philhsu/)的[实现](https://leetcode-cn.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/solution/c-jian-ji-dai-si-lu-by-philhsu/)
注意以下几点：

1. 需要一个辅助节点`res`，因为头节点也有可能被删掉
2. 将前缀和用哈希表`mp`存储，要将辅助节点也存存进去，即`mp[0] = res`。因为考虑输入为`[-1,1]`，假如没有把把`res`加入`mp`。会返回错误的值
3. 删除区间时也要消除区间的前缀和



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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        ListNode *res = new ListNode(0);
        res->next = head;
        mp[0] = res;
        ListNode *p = res, *_next;
        int cur = 0, cur_tmp = 0;

        while(p = p->next){
            cur += p->val;
            if(mp.find(cur) != mp.end()){
                //删除区间
                ListNode *temp = mp[cur];
                _next = temp->next;
                temp->next = p->next;
                cur_tmp =  cur;

                // 删除区间的前缀和
                while(_next != p){
                    cur_tmp += _next->val;
                    mp.erase(cur_tmp);
                    _next = _next->next;
                }
            }
            else{
                mp[cur] = p;
            }
        }
        return res->next;
    }
};
```