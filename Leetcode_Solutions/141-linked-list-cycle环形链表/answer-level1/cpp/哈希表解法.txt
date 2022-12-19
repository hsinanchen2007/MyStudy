### 解题思路
*方法一：*看到题目首先想到的一个方法，就直接用了map，没想到效率很低，超过了5%的人。。。
记录每一个节点的地址，如果存在一个相同的地址被记录了两次，说明有两个链指向了这个地址，即有循环链表。
*方法二：*哈希表解法应该是更适合用set，毕竟我们就是要知道结点的地址是不是已经被用过了。
### 头文件
```
#include <map>
#include <set>
```


### 代码
map：
```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> map;
        while (head != 0) {
            map[head]++;
            if (map[head] > 1) 
                return true;
            head = head->next;
        }
        return false;
    }
};
```
set:
```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> set;
        while (head != 0) {
            if (set.find(head) != set.end())
                return true;
            set.insert(head);    
            head = head->next;
        }
        return false;
    }
};
```
