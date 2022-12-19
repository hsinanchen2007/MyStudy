### 解题思路
相当于将n块糖的分给k个小朋友，小朋友拿到的糖数量差不能超多1。
(1)每个小朋友至少能得到n/k块糖，剩余n%k块糖；
(2)前n%k个小朋友有能多得到1块糖。
**使用双指针记录分割点。**
时间复杂度：遍历了两遍链表O(2n)，复杂度属于O(n)
空间复杂度：O(1)
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode *> res;
        ListNode * cur = root;
        ListNode * pre = NULL;
        //一共n块糖
        int n = 0;
        while(cur){
            cur = cur->next;
            ++n;
        }
        int size   = n / k;//每个小朋友至少能得到n/k块糖
        int remain = n % k;//剩余n%k，分给前n%k个小朋友，保证小朋友的糖数量差不超过1
        int idx = 1;
        cur = root;
        for(int i = 0; i < k; ++i){
            res.push_back(cur);
            if(cur == NULL) continue;
            //分给当前小朋友n/k块糖
            while(idx < size){
                cur = cur->next;
                ++idx;
            }
            idx = 1;
            //分给当前小朋友n/k块糖之后，如果有剩余，多给一块
            if(size > 0 && remain > 0){
                cur = cur->next;
                --remain;
            }
            //双指针分割点
            pre = cur;
            cur = cur->next;
            pre->next = NULL;
        }

        return res;
    }
};


```