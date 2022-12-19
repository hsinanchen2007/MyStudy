### 解题思路
先将链表的所有节点的指针放入一个 vector<ListNode*> v1中，若翻转相邻节点，则令 int x=2;  将v1中的元素分为 v1.size()/x组（若节点个数为奇数，则加一组），
再创建一个vector v2，将v1的每个分组的元素倒序放入v2中， 最后对v2的元素进行指针重定向 。

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
#include<vector>
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return NULL;              //若为空链表，返回空指针
        if (head->next == NULL) return head;        //链表只有1个元素，返回头节点
        ListNode * m = head;                        //定位头指针，也可以直接用head
        int x = 2;                                  //这里是翻转相邻的节点，所有x=2，也可以翻转任意个数的节点，也就是下一道题目的k值
        vector<ListNode*> v1;                       //创建 v1， 用来顺序存储 链表的节点元素
        while(m != NULL)
        {
            v1.push_back(m);                        //依次将节点放入v1中
            m = m->next;                            //移动定位指针
        }
        vector<ListNode*> v2;                       //创建 v2， 用来存储 翻转后的链表元素
        for(int i=0; i<v1.size()/x; i++)            //假设 链表为[1,2,3,4,5] 有5个元素, 则先分为5/x = 2组（取模运算），剩下的最后一组元素（个数小于x）最后放入v2，不影响
        {
            for(int j=i*x + 1; j>= i*x; j--)        //对每个小分组进行倒序，并放入v2中，逆序遍历，用 j--
            {
                v2.push_back(v1[j]);
            }
        }
        if(v2.size() < v1.size()){v2.push_back(v1.back());}  //这里如果链表元素个数不能被x整除，则v2的元素个数会比v1少最后一组的个数，需补全最后一组
        v2.back()->next = NULL;                     //这里要先对v2的最后一个元素进行  ->next=NULL; 避免下一步操作出现无穷循环
        for(int i=0; i<v2.size()-1; i++)
        {
            v2[i]->next = v2[i+1];                  //重要的一步，其实v2中的每个元素都是一个指针，指向一个节点，但该节点的 .next指向的下一个位置还是和v1一样的，所有要重新定位
        }

        return v2[0];                               //返回v2的第一个元素，也就是翻转后链表的头节点
    }
};
```