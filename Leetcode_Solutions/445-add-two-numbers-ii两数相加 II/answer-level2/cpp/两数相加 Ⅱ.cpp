### 解题思路
题目要求：**两个非空链表**，除了数字0以外，这两个数字都不会以零开头
方法一：利用栈的特性：先进后出。  
根据两个栈和进位cnt的结果构建链表。
构建链表用了尾插法。
我在这以图的方式进行描述。
![尾插法创建链表.jpg](https://pic.leetcode-cn.com/bc9faf2fe7e24dc7bea2b317473983fb2771151f2910d2c35e87ce218d44cf5c-%E5%B0%BE%E6%8F%92%E6%B3%95%E5%88%9B%E5%BB%BA%E9%93%BE%E8%A1%A8.jpg)

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
 /*利用栈的知识*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> a,b;
        while(l1){
            a.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            b.push(l2->val);
            l2=l2->next;
        }
        ListNode* newNode = new ListNode(0);
        ListNode* current = NULL;
        int cnt=0,n1,n2,sum;//cnt=进位
        while(!a.empty() || !b.empty() || cnt){
            if(!a.empty()){
                n1 = a.top(); //栈顶元素
                a.pop();
            }else{
                n1 = 0;
            }
            if(!b.empty()){
                n2 = b.top(); //栈顶元素
                b.pop();
            }else{
                n2 = 0;
            }
            sum = n1+n2+cnt;
            cnt = sum/10;

            //尾插法建立链表
            current = new ListNode(sum%10);
            current->next = newNode->next;
            newNode->next = current;
        }
        return newNode->next;
    }
};
```