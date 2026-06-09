### 解题思路
这道题第一次做的时候就想直接用find(v.begin(),v.end(),val)查。。 结果时间通过不了。
最后还是用了set来存储vector的值。 使用s.find(val)查。 这样的速度更快？？  就通过了

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
    // 执行用时 :64 ms, 在所有 C++ 提交中击败了45.28% 的用户
    // 内存消耗 :21.8 MB, 在所有 C++ 提交中击败了6.45%的用户
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> s(G.begin(), G.end());//用一个set来存储G中的值。方便查找。
        // for(int i = 0;i<G.size();++i){
        //     s.insert(G[i]);
        // }
        if(head==nullptr||G.size()<1) return 0;
        int num = 0, len = 0;
        while(head){
            if(s.find(head->val)!=s.end()) ++len;//调用find函数。直接找。速度快。
            else{
                if(len!=0) ++num;
                len=0;
            }
            head = head->next;
        }
        return len>0?num+1:num;
    }
};
```