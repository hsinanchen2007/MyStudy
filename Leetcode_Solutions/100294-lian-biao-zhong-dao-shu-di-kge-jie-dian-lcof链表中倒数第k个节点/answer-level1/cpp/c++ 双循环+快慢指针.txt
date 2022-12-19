### 解题思路

&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;常规思路，设置一个指针从头结点遍历到尾结点，再回溯到倒数第k个结点，但由于本题是单链表，显然不能回溯。不过我们可以用两次循环，第一次循环遍历整个链表求出其结点总数，而后再从头遍历到第`count - k + 1`个结点，同时也是倒数第k个结点，返回当前指针即可。

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* dimmyNode = new ListNode(0);
        ListNode* cur = head;
        dimmyNode->next = head;
        int count = 0;
        //求表长
        while(cur){
            count++;
            cur = cur->next;
        }

        //求倒数第k个，即求正数第count - k + 1个
        ListNode* res = head;
        ListNode* pre = dimmyNode;
        int num = 1;
        while(num < count - k + 1){
            num++;
            pre = res;
            res = res->next;
        }
       
        return res;
    }
};
```
<br/>

&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;执行用时：8ms～显然，循环两次不够美丽。此时需要我们继续改进代码，那如何实现一次遍历即可得出结果呢？

### 改进策略
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;对于链表问题，遇事不决双指针，而且是快慢指针。
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;定义两个指针。`first`指针先从头结点遍历`k - 1`步，当要走第`k`步时，`first`和`second`指针同时遍历(`second`也从头结点开始遍历)，之后两个指针同步遍历以维护两指针之间的距离`k - 1`，直到`first`指针走到尾结点时，我们发现`second`指针恰好在倒数第`k`个结点上，返回`second`即可。给出一个示意图：

![在这里插入图片描述](https://pic.leetcode-cn.com/5ce63d6ffdb15294e542a06ac39856efae0adfb53809cdeec6866757f96cbfd2.jpg)

<br/>


&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;**注意**：需要考虑边界问题。

 1. 输入指针为空；
 2. 输入链表结点总数小于k；
 3. 输入k为0时无意义。

&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;对于问题1，我们可以在head前设置一个虚拟头结点`dimmyNode`。对于问题2，将循环结束条件设为`first -> next`。对于问题3，设置一个记录步数的变量`step`并赋初值`0`，时刻判断与`k-1`的关系。
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;执行用时:4ms

### 代码

```cpp
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        //if(head == NULL || k == 0)
        //    return NULL;
        ListNode* dimmyNode = new ListNode(0); //创建虚拟头结点
        dimmyNode->next = head;
        ListNode* first = dimmyNode;      //双指针
        ListNode* second = dimmyNode;
        int step = 0;                     //指针操作步数
        while(first -> next){             //当循环结束后，first位于尾结点，second恰好位于倒数第k个结点
            if(step < k - 1){             //一开始first先动，直到first完成k-1步操作之后
                step++;
                first = first->next;
            }
            else{                         //第k步开始，first和second同时动
                assert(step == k - 1);    //维护first和second之间距离k-1步操作
                second = second->next;
                first = first->next;
            }            
        }
        return second;
    }
};
```


<br/>
