![image.png](https://pic.leetcode-cn.com/7b05dfab5a3141ead0c00a9f1801d3f0b2c1f60354dcb1225c4edddceec6784c-image.png)
> 说实话，时间和空间根本就是和服务器有关，但是为了把大家“骗过来”，咳咳咳。

言归正传，下面将从**思想、实现**两个个方面给大家讲解
1. 思想
>1. 首先需要遍历链表得到链表长度length。
>2. 公共长度size_pub=length/k。
>多余的链表元素大小size_sp=length%k，我们将它**分成size_sp个元素分别插入到之前的分组中**，这就保证了**分组间大小最多差1**
>3. 由于前面的一定要大于后面的，我们每次将表头插入vector，向后遍历size_pub个，size_res!=0的话，就再遍历1次，（保证了多余元素优先在前面分配）--size_res。
>4. 注意还需要记录分组最后一个结点rear_ptr，rear_ptr->next=nullptr,与原链表断去连接。


代码


    class Solution {
    public:
        vector<ListNode*> splitListToParts(ListNode* root, int k) {
            vector<ListNode*> answer;   //容纳答案的vector
            ListNode* p=root;   //p是用来遍历的指针
            int length=0;   //记录链表长度
            while(p)
            {
                p=p->next;
                ++length;
            }   //得到链表长度
            int size_public=length/k;   //每个分区至少有的元素个数
            int size_sp=length%k;   //前size_sp个分区会额外多一个元素
            p=root; //将遍历指针归于表头位置
            ListNode* rear_ptr=nullptr; //用来记录每个分区的最后一个节点，方便断链
            for(int i=0; i<k; ++i)
            {
                answer.push_back(p);    //将分区头部存入vector
                for(int j=0; j<size_public; ++j)
                {
                    if(j==size_public-1)
                        rear_ptr=p; //记录公共部分链尾
                    p=p->next;  //p指向新分区的开始
                } 
                
                if(size_sp>0)   //如果还在前size_sp个分区内的话
                {
                    rear_ptr=p; //更新链尾指针到下一个位置
                    p=p->next;
                    --size_sp;  
                }
                if(rear_ptr!=nullptr)   //只有当链尾指针不是指向空时才能断链
                    rear_ptr->next=nullptr;
            }
            return answer;
        }
    };
