### 解题思路
这道题首先想到的是求出数组的长度。然后均分。余数大小表示前多少个子链表的节点个数多一个。
重点是切断部分。首先把root头结点赋值给数组。  让一个p来遍历子链表的内部。 遍历完后在p后面连上nullptr， 就切断了。

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

    // 执行用时 :12 ms, 在所有 C++ 提交中击败了35.20% 的用户
    // 内存消耗 :9.1 MB, 在所有 C++ 提交中击败了90.00%的用户
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res(k, nullptr);
        int len = 0;
        ListNode* p = root;
        while(p){
            ++len;
            p = p->next;
        }
        int num = len/k, n = len%k;
        for(int i = 0;i<k;++i){//把链表截取成子链表，
            res[i] = root;//获取头结点。
            int times = n>0?num+1:num;
            for(int j = 0 ; j<times ; ++j){
                p = root; //这里是用p来截取。p是res[i]的链表里的节点，res[i]存的是头结点。若p改变，res[i]也会改变
                root = root->next;
            }
            if(n>0) --n;
            if(p) p->next = nullptr;//若p存在，切断。
        }
        return res;
    }



};
```