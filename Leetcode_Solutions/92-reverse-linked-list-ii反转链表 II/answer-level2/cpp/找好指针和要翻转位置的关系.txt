执行用时 : 4 ms , 在所有 C++ 提交中击败了 91.28% 的用户 内存消耗 : 8.4 MB , 在所有 C++ 提交中击败了 95.18% 的用户

就是得搞清楚指针和要反转序数的关系。主要思想是让开始翻转的那个节点不动，然后如果他的下一个节点是要翻转的，则让他翻转到开始节点的前面，这样依次下去，不停的让要翻转的节点逐步跑到前面去，实现翻转： A-B-C-D-E-F : 假如B到E要翻转 B为开始节点，B且始终保持指针不动 则：先吧C放到B前面，然后变成A-C-B-D-E,接下来 B还是不动 再把D放到C前面： A-D-C-B-E-F。最后把E在放到最前面去，变成A-E-D-C-B-F.这样则一次遍历完成翻转。

1. 因为要对链表的前面节点进行翻转，例如 A-B-C-D，要从B开始翻转的话，不管后面从哪截止，A点肯定是要设置一个指针的，方便操作。
2. 对于末尾，因为要将最后一个要翻转的节点放到最前面，所以最后那个翻转的节点要设置一个指针，同时要翻转的那个节点的前一个节点，也要设置一个指针，因为这样要翻转的节点的后面那个节点才能和要翻转的节点的前面的节点连上。 所以一共对于翻转要设置三个指针。

总共的翻转次数是n-m， 开头指针pre的移动次数是m-1, 初始化last指向pre的下一个，tmp指向last的下一个。 pre为开始节点（m-1位置），移动到要翻转位置前一个node就再也不动了。last(m号位置）节点初始化后也再也不动了。要变化的就是只有tmp节点，不断充当尾巴变成头的搬运.
```
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *pre=new ListNode(-1);
        pre->next=head;
        ListNode *h=pre->next;
        for(int i=0;i<m-1;i++)
        {
            pre=pre->next;
        }
        if(pre!=NULL)
        {
            ListNode *last=pre->next;
            for(int i=0;i<n-m;i++)
            {
                if(last!=NULL)
                {
                    ListNode *tmp=last->next;
                    if(tmp!=NULL)
                    {
                        last->next=tmp->next;
                        tmp->next=pre->next;
                        pre->next=tmp;
                    }
                }
            }
        }
        if(m==1)
        {
            return pre->next;
        }
        return h;
    }
};
```
