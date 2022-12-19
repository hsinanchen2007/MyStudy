1.  先计算链的长度length, 然后cutSize=length/k计算该断开的位置，由于题目要求“排在前面的部分的长度应该大于或等于后面的长度“，所以如果length%k存在（即有余数）的h话， cutSize还要+1，得到第一部分的链表长度，断开；
2.  用断开后的下一部分链表重复步骤1，因为已经得到第一部分了，执行第二次迭代时k要-1。直到k=1，把剩下链表节点作为最后一部分即可。
3.  最终得到各个部分的链表，过程中用vector保存各个部分作为结果。
```
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res;
        helper(res, root, k);
        return res;
        
    }
    void helper(vector<ListNode*> &res, ListNode* root, int k){
        if(!root){
            for(int i=0; i<k; ++i){
                res.push_back(NULL);
            }
            return ;
        }
        
        if(root && (!k || k == 1)){
            res.push_back(root);
            return ;
        }
        
        ListNode* p = root;
        int length = 0;
        while(p){
            ++length;
            p = p->next;
        }
        int cutSize = length/k;
        if(length%k){++cutSize;}
        ListNode* remain = cut(root, cutSize);
        res.push_back(root);
        helper(res, remain, --k);
    }
    
    ListNode* cut(ListNode* l, int cutSize){
        while(--cutSize && l){
            l = l->next;
        }
        if(!l){return NULL;}
        ListNode* remain = l->next;
        l->next = NULL;
        return remain;
    }
};
```
