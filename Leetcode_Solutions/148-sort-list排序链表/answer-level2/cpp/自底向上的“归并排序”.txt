自顶向下的归并排序，由于用到递归，而递归需要用到系统栈，递归的深度是logn，所以需要额外的空间O(logn)，因此应该采用自底向上的归并排序。
整体思路如下：
第一次：将整个序列分为两两一段：[a0,a1]、[a2,a3]、...、[an-2,an-1]
       每段都分别进行排序，最后一段个数可能不足于区间长度，需要考虑当指针走到空即可
第二次：将整个序列分为4个一段：[a0,a1,a2,a3]、...
       每段都分别进行排序，根据上一次排序的结果进行归并排序
...
当每段的长度大于n时即结束
时间复杂度：O(nlogn)
空间复杂度：O(1)
```
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
    ListNode* sortList(ListNode* head) {
        auto dummy=new ListNode(-1);
        dummy->next=head;
        int n=0;
        for(auto p=head;p;p=p->next) n++;
        for(int i=1;i<n;i*=2)  //每次都是2^i长度为一段
        {
            auto begin=dummy;
            for(int j=0;j+i<n;j+=i*2)  //归并每一段
            {
                auto first=begin->next,second=first;
                for(int k=0;k<i;k++)   //first为第一段起点，second为第二段起点
                    second=second->next;
                int f=0,s=0;   //记录前后两段每次已归并的长度
                while(f<i&&s<i&&second)
                {
                    if(first->val<second->val)
                    {
                        f++;
                        begin=begin->next=first;
                        first=first->next;
                    }
                    else
                    {
                        s++;
                        begin=begin->next=second;
                        second=second->next;
                    }
                }
                while(f<i)  //把前一段剩下的数据直接放在后面
                {
                    f++;
                    begin=begin->next=first;
                    first=first->next;
                }
                while(s<i&&second)  //把后一段剩下的数据直接放在后面
                {
                    s++;
                    begin=begin->next=second;
                    second=second->next;
                }
                begin->next=second;  //把这段归并好的数据连接上下一段未归并的数据
            }
        }
        return dummy->next;
        
    }
};
```

