### 解题思路
通过添加一个头结点，使得当m = 1的情况好处理。
![捕获.JPG](https://pic.leetcode-cn.com/a2f234bc8c9a3fdc81ae04c970fe27c67e29cbb77827f5622b3657a6b07f1e65-%E6%8D%95%E8%8E%B7.JPG)

### 代码

```cpp
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *Head = new ListNode(0);
        Head->next = head;                          //添加头结点Head
        ListNode *p = Head;
        ListNode *temp;        //存放第m个结点，方便最后连接（因为最终第m个结点连接第n+1个结点）
        int flag = 1;                               //标记变量
        while(p)
        {
            if(p->next&&flag==m)
            {
                ListNode *q = p->next;              
                temp = q;                           //存放第m个结点
                p->next = NULL;
                while(q&&flag<=n)                   //反转代码
                {
                    ListNode *s = q;
                    q = q->next;
                    s->next = p->next;
                    p->next = s;
                    flag++;
                }                                   
                temp->next = q;  //退出循环后q为第n+1个结点，所以让存放第m个结点的temp指向它，连接起来
                return Head->next;         //后面不用管，直接return    
            }
            p = p->next;                   //如果始终小于m，那么p一直后移，直至等于m 或 为NULL
            flag++;
        }
        return Head->next;
    }
};
```