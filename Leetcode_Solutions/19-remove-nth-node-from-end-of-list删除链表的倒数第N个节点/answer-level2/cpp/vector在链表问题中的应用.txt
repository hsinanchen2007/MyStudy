在刷题的过程中遇到过很多有关链表的问题
ListNode作为一种自定义结构体
自然而然的可以应用vector来解题
看题解中没有提及，在此把这种思路和大家分享
值得注意的是：**vector内的数据类型应该是ListNode***
```
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        vector<ListNode*> vec;
        while(head->next != nullptr)
        {
            vec.push_back(head);    //把链表中的所有节点放到vector中
            head = head->next;
        }
        vec.push_back(head);    //别忘了最后一个节点
        vec.erase(vec.begin()+vec.size()-n);    //删掉要求的那个节点
        if(vec.size() == 0){return nullptr;}
        for(int i = 0 ; i < vec.size()-1 ; i ++)
        {
            vec[i]->next = vec[i+1];    //将容器内的点前后相连
        }
        vec[vec.size()-1]->next = nullptr;  //最后一个节点确保next为空
        return vec[0];  //返回第一个节点即可
    }
};
```
效果还不错，大家可以尝试在其他题目中尝试应用
![屏幕快照 2019-09-19 上午11.11.38.png](https://pic.leetcode-cn.com/5d070d9bcc3cffe69b63ad2e76f8ee516f3954a0794d5b656eaa5e1b11efa766-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-09-19%20%E4%B8%8A%E5%8D%8811.11.38.png)
