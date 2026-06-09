### 解题思路
这个题特殊情况的判断阻碍了我很久，比如这些测试用例：
[7032,15013,6890,8877,...,11]  -1
[1]  -1
[1]  1

目前发现的原因是对while循环的一些技巧没有掌握，
通过这类问题的练习发现如果直接将变量的初始化也写在while内代码会更加清晰，如这次的解答：
```c
while(true){
        if(fast==NULL||fast->next==NULL) return NULL;
        slow = slow->next;
        fast = fast->next->next;  
        if(fast==slow) break;      
    }
```

这种方式将while的跳出条件写在了里面的if语句中
这种方式的好处是能够将一般情况下的执行情况抽象的在while中表达出来。

也可以这样作比方：
```c
    slow=head;
    fast=head;
```
此时是静止状态
```c
    while(true){
        ...
    }
```
这个时候便是动态，开始执行算法

相比于[弗洛伊德的乌龟和兔子（循环检测)](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/fu-luo-yi-de-de-wu-gui-he-tu-zi-xun-huan-jian-ce-g/)问题，本问题情况稍微复杂了一些，这使得那时采用的将初始化写在while之外显得不是特别有效。

参考[环形链表 II（双指针法，清晰图解）](https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/)
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast,*slow,*find;
    slow=head;
    fast=head;

    while(true){
        if(fast==NULL||fast->next==NULL) return NULL;
        slow = slow->next;
        fast = fast->next->next;  
        if(fast==slow) break;      
    }
    find=head;
    while(find!=slow){
        find=find->next;
        slow=slow->next;
    }
    return find;
}
```