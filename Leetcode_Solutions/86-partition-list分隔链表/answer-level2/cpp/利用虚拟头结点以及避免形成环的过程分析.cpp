## 写在前面
&emsp;&emsp;官方题解的思路写得已经比较清楚了，这里主要针对一部分盆友对`after->next = NULL;`的疑问的解决。其实对于这个问题最好的解决办法就是自己打断点过一遍程序就清楚明了了。

## 思路
- 引入双指针before，after分别用于存储小于x和大于等于x两个链表
- 两链表设置虚拟头结点可以减少条件判断(自行举例)
- 用head遍历原有链表
- 当值小于x，将该结点接入before链表中
- 当值大于等于x，将该结点接入after链表中
- head为空跳出循环
- 现在将after链接到before后
- 要注意处理掉虚拟头结点，也就是before和after在链接和返回是向后移一位即可达到处理虚拟头结点的效果

&emsp;&emsp;要注意体会在这个过程中，我们没有使用任何额外的空间，只是将原有链表结点进行移动。对于`after->next = NULL;`这一步，消除野指针、避免环链表显然是很概括的解释。这里我利用一个简单实例`[2,1] 2`手绘一个示意图帮助你过一遍程序。

## 示意图
![示意图(Draft)-4.jpg](https://pic.leetcode-cn.com/bc34ac40304d807490c58f0a34bd5b4329a2a3fdbd23625156610d7471867405-Untitled%20\(Draft\)-4.jpg)

## 算法
```
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)
            return head;
        ListNode* before = new ListNode(0);
        ListNode* headBef = before;
        ListNode* after = new ListNode(0);
        ListNode* headAft = after;

        while(head){
            if(head->val < x){
                before->next = head;
                before = before->next;
            }
            else{
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        after->next = NULL;
        before->next = headAft->next;
        headBef = headBef->next;
        return headBef;
    }
};
```

>如果有错误或者不严谨的地方，请务必给予指正，十分感谢。
>本人blog：<https://zhengguanyu.github.io>