### 解题思路
 
![1578144422(1).png](https://pic.leetcode-cn.com/06e396f617c221320637506fadedb9679b84feefe2eb1574bc9b1914ccbfb978-1578144422\(1\).png)
   还没有刷到栈，因此用数组存储链表元素。设置一个计数器count，发现数组下标与对应转换应该乘的2的次方数之和是固定的，等于count-1,个人认为这是关键点。然后采用for循环计算即可。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    int count=0;
    int SUM=0;
    int i,j,n;
    int a[30];
    int *m;
    while(head!=0)
    {
      a[count]=head->val;
      head=head->next;
      count++;
    }
  for(i=count-1;i>=0;i--)
  {
      n=count-1-i;
      m=&a[i]; 
      j=*m;
      SUM+=j<<n;
  }
    return SUM;
}
```