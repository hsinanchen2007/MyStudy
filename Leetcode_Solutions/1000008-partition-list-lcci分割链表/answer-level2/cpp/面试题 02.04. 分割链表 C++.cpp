### 解题思路
1、将链表节点放入数组，使用快排的partition方法，最后再建立新的链接顺序


### 代码

```cpp

//左边小于pivot 右边大于等于pivot
void partition(vector<ListNode*>& v, int x)
{
    int less = -1;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v.at(i)->val < x)
        {
            swap(v.at(i), v.at(++less));
        }
    }
}

//左边小于pivot 中间等于pivot 右边大于pivot
void partition2(vector<ListNode*>& v, int x)
{
    int less = -1;
    int more = v.size();
    
    int i = 0;
    while(i < more)
    {
        if (v.at(i)->val < x)
        {
            swap(v.at(i), v.at(++less));
        }
        else if (v.at(i)->val > x)
        {
            swap(v.at(i), v.at(--more));
            continue; //继续
        }
        ++i;
    }
}

ListNode* partition(ListNode* head, int x) {

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    
    vector<ListNode*> v;
    while (head)
    {
        v.push_back(head);
        head = head->next;
    }

    partition(v, x);

    //建立新的链接
    for (int i = 0; i < (int)v.size() - 1 ; ++i)
    {
        v.at(i)->next = v.at(i + 1);
    }
    v.back()->next = nullptr; //注意别忘了

    return v.at(0);
}