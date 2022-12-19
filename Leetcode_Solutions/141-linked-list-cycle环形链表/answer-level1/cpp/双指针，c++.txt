### 解题思路
这是卡片上的一道题，原题提示很明确可以用双指针，解法一我不多啰嗦

### 代码

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)return 0;
        ListNode *i=head,*j=head;
        while((*j).next!=NULL){
            j=j->next;
            if((*j).next==NULL)return 0;
            if(j==i)return 1;
            i=i->next;
            j=j->next;
            if(j==i)return 1;
        }
        return 0;
    }
};
```
剩下的解法有时间再写!
![2020-02-03 16-52-02 的屏幕截图.png](https://pic.leetcode-cn.com/14c4f97c01d877f60bed56c47c8595719871705da1e63468921c589be89c6fcb-2020-02-03%2016-52-02%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)
纪念一下总算突破及格线的我
