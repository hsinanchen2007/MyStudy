###### 看到题的第一想法是，这道为什么是hard难度？不是每次找第一项最小的链表串起来就好了吗？然后看到要求分析时空复杂度， 明白原来难在这里
###### 如果直接暴力时间复杂度是O(nk)，遍历链表是必须的，也就是n不能优化，只能从k，也就是选择第一项最小的链表上做文章，比线性k快的想到log(k)，那么用堆也就是理所当然了。看代码：
---
```
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        curSize = lists.size(); //堆的大小
        lists.push_back(lists.at(0));   //堆下标从1开始
        ListNode *pre = new ListNode(INT_MAX); //哨兵
        ListNode *ans = pre;
        build(lists); //建堆
        while(lists.at(1)!=nullptr) //堆顶不是空指针说明还有元素没有遍历到
        {
            ans->next = lists.at(1);
            ans = ans->next;
            lists.at(1) = lists.at(1)->next;
            down(lists, 1); //堆顶修改为下一个节点后下滤
        }
        if(pre!=nullptr)
        {
            ans = pre->next;
            delete pre;
            return ans;
        }
        else return nullptr;
    }
private:
    int curSize;
    void down(vector<ListNode*> &lists, int hole)
    {
        auto comp = [](ListNode* p1, ListNode* p2){ //ListNode*版的greater<>的lambda表达式，也可以用函数
            if(p1 == nullptr) return true; //空链表不予考虑直接下滤到堆底
            else if(p2 == nullptr) return false;
            else return (p1->val) > (p2->val);
        }; 
        auto tmp = lists.at(hole);
        int child=hole;
        while(hole*2<=curSize)
        {
            child = hole*2;
            if(child!=curSize && !comp(lists.at(child+1), lists.at(child))) child++;
            if(!comp(tmp,lists.at(child))) break;
            else lists.at(hole) = lists.at(child);
            hole = child;
        }
        lists.at(hole) = tmp;
    }
    void build(vector<ListNode*> &lists)
    {
        for(int i=curSize/2; i>0; i--)
        {
            down(lists, i);
        }
    }
};
```