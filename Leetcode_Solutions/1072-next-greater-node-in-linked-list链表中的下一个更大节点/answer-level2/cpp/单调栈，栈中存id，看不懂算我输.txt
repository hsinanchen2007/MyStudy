![image.png](https://pic.leetcode-cn.com/cd6132c87dfc7166c76fb05e0d24bf40f15ab9229e5edbc37741578eaef38883-image.png)
```
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) 
    {
       //先把链表转为数组
       vector<int> temp;
       int length=0;
       while(head)
       {
           temp.push_back(head->val);
           head=head->next;
           length++;
       }
       vector<int> res(length);//初始化最后输出的数组
       stack<int> s;//单调辅助栈
       //遍历上述转化过来的数组
       for(int i=0;i<length;i++)
       {
           while(!s.empty()&&temp[i]>temp[s.top()])
           {
               res[s.top()]=temp[i];
               s.pop();//也就是这个id已经被安排了，不再需要了
           }     
           s.push(i);//push进去的是数组的id
       }
       return res;   
    }
};
```


