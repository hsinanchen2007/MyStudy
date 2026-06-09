/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 执行用时 :56 ms, 在所有 C++ 提交中击败了60.11%的用户
内存消耗 :16.2 MB, 在所有 C++ 提交中击败了87.50%的用户
 */


class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    
    //蓄水池抽样，感觉更像流水线抽样，不知道多少个不知道什么时候结束，参考https://www.cnblogs.com/snowInPluto/p/5996269.html
    //要求：1.不知道链表长度，常数空间复杂度，就是不能把链表存起来然后遍历计算len，所以没办法知道len
    //如果可以使用的话，直接选择rand()/len就行了
    //2. 等概率,证明请看以上链接
   
    ListNode* nod;
    Solution(ListNode* head) {
        this->nod = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        if(nod==NULL)
            return 0;
        int res = nod->val;//第一步选中1个数
        
        ListNode* cur=nod;
        cout<<rand()%2<<"  "<<endl;
        
        int ind=1;//当前位置
        while(cur->next!=NULL){
            cur=cur->next;
            if((rand()%(ind+1))==ind)
                res=cur->val;
            ind++;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

