![Image.png](https://pic.leetcode-cn.com/e2434144e83ff00f6c2d53e3334485b86cfd2751849840d01b56fd424f017351-Image.png)
提交后，第一次不看题解还出现双100%，所以斗胆挂出来了，只是提供一种可行性吧，本人菜鸟，求大神们轻点喷。

**解题思路：**
- 采用链表遍历标准框架，采用双指针pre和cur（标准框架是参照[@nettee](/u/nettee/)大佬的公众号《面向大象编程》，顺便感谢大佬让我这种菜鸟也能不看题解做出来这道题）
- 在遍历到m节点时记录当前cur和pre为cur0和pre0，等到第n节点的时候要用
- (m,n)区间，采用常规 cur->next = pre的反转操作
- 在遍历到n点时(cur指向n)，除了反转操作外，还要将pre0->next指向cur，将cur0->next指向cur->next，如下图：
![Image2.png](https://pic.leetcode-cn.com/ca59dd700c5a982658b316e327fa8a55c626c2918bb31d373166b088e0bcaaf8-Image2.png)

```
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* pre0,*cur0;
        int count = 1;
        while(cur != NULL && count <= n){
            //当cur为m时
            if(count == m)
            {
                //在头节点,则
                pre0 = pre;
                cur0 = cur;
                //常规处理
                pre = cur;
                cur = cur->next;
            }
            //当cur在m,n之间时
            else if(count > m && count < n)
            {
                ListNode* temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            }
            //当cur为n时
            else if(count == n)
            {   
                //将cur的next指向pre
                ListNode* temp = cur->next;
                cur->next = pre;
                //将pre0的next指向第n元素
                if(pre0 == NULL) head = cur;
                else pre0->next = cur;
                //将指向m的cur0的next指向n后第一个元素
                cur0->next = temp; 
                //更新pre和cur
                pre = cur0;
                cur = temp;
            }
            else
            {
                //常规处理
                pre = cur;
                cur = cur->next;
            }
            //常规处理
            ++count; 
        }
        return head;
    }
};
```
发布后觉得代码有些冗余，又修改了下：
```
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* pre0,*cur0;
        unsigned int count = 1;
        while(cur != NULL && count <= n){
            //当cur为m时,记录一下当前cur和pre
            if(count == m)//在头节点,则记录当前pre和cur供后续连接使用
            {
                pre0 = pre;
                cur0 = cur;
            }
            //当cur在(m,n]之间时，反转链表
            if(count > m && count <= n)
            {
                ListNode* temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            }
            else         //常规迭代处理
            {
                pre = cur;
                cur = cur->next;
            }
            //常规处理
            ++count; 
        }
        //最后的链接操作
        //将pre0的next指向第n元素,此时pre指向n，cur指向原始链表中n的下一个元素
        if(pre0 == NULL) head = pre;
        else pre0->next = pre;
        //将指向m的cur0的next指向n后第一个元素
        cur0->next = cur;

        return head;
    }
};
```



