先遍历链表,找出个数,算出每组的数量,然后利用计数器来实现分组操作
```cpp
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> result={root};
        ListNode * timo_node=root;
        ListNode * ind_node;//存储节点
        int i=0,j,The_whole,The_remain;
        while(timo_node&&timo_node->next) 
        {   i+=1;//查询长度
            timo_node=timo_node->next;}
        The_whole=i/k;//每组中最少个数
        The_remain=i%k;//有多少组的个数比最少组多1
        timo_node=root;
        while(timo_node)
        {
            ListNode* node2=timo_node;//新建节点,,作为vector的一个元素
            j=0;//本组元素数量
            if(The_remain>=0)//若remain有剩余,,本组元素数量+1
            {
                j+=1;
                The_remain--;
            }
            for(j+=The_whole;j>1;j--)//遍历本组元素
            {
                timo_node=timo_node->next;
            }
            result.push_back(timo_node->next);//入栈
            ind_node=timo_node->next;//断节点,,进入下一节点
            timo_node->next=NULL;
            timo_node=ind_node;
        }
        result.pop_back();
        while(result.size()<k)//若组数不足K,,补足空值
        {
            ListNode* neo_node=NULL;
            result.push_back(neo_node);
        }
        return result;
    }
```