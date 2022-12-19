# 解题思路
用一个长度为20001的数组存一下链表中出现的值，用两个指针cur和pre分别表示当前的节点和上一个不重复的节点，遍历该链表：
1. 如果结点的值出现在数组中，则跳过该节点；
2. 否则，将这个值添加到数组中，pre和cur继续向后移。
下面看图

![图片1.png](https://pic.leetcode-cn.com/cc6ef80aef1a84f7270dd87677fcf7eb75a757f7abf34c510fde7cf2f06826f3-%E5%9B%BE%E7%89%871.png)

![图片2.png](https://pic.leetcode-cn.com/aaa71abba58f9042089c5a0e286b53ec58f1481eaa29f9e849b3a87b603aa7dd-%E5%9B%BE%E7%89%872.png)

![图片3.png](https://pic.leetcode-cn.com/9df063dfd1e873ca58905df391541f77666faa6a76f0480cc3ffb126c756b659-%E5%9B%BE%E7%89%873.png)


# code
```
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        int a[20001]={0};
        if(head==NULL)  return NULL;
        ListNode* pre=head;
        ListNode* cur=head->next;
        a[pre->val]++;//cur指针从第二个结点开始，所以先存一下头结点的值
        
        while(cur)
        {
            if(a[cur->val]==0)
            {
                a[cur->val]++;
                pre=pre->next;
                cur=cur->next;
            }
            else
            {
                pre->next=cur->next;
                cur=pre->next;
            }
        }
        return head;
    }
};
```
