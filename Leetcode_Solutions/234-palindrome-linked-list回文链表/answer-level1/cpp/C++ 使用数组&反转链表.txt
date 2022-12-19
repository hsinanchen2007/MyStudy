## 方法 1

解决这个题最直观的方法就是借用数组保存整个链表的值，然后再使用**首尾双指针**进行回文判断。

**时间复杂度O(n)，空间复杂度O(n)**

## 方法 2

要求空间复杂度为O(1)。检查链表是否回文，**也就是说两个指针分别指向链表首尾两端，然后向链表中间进行移动并判断**，这个操作和判断数组字符串回文是一个道理。

所以，我们可以有这样的一个想法：**对链表中间往后的部分进行链表的反转操作**，然后按照上述的做法比较即可。而关于链表的反转，在前面已经遇到了，请参考：**[反转链表](https://leetcode-cn.com/problems/reverse-linked-list )**

+ 先找到链表的中点 ： 这个很简单，快慢指针就可以办到了，`slow = slow->next; fast = fast->next;`
+ 一次遍历之后，`slow`所指即为链表中点
+ 然后对 `slow`之后的节点进行反转，不需要区分奇偶的，这里用图简单说明一下：

**偶数节点情况：**
![偶数](https://pic.leetcode-cn.com/8ca0b68fc9000c3bc43dff79f16a077f8fd156257983aa5251917b6e741feea7)

**奇数节点情况：**
![奇数](https://pic.leetcode-cn.com/18d8692f6844402f85cfa51943a43227d09ea2527eb16b8e51db67096ddf2d90)


这样我们可以看出，反转链表之后，从head和curNode两个链表头开始往中间遍历，直到任一方节点为空结束循环。


**代码：**

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
    bool isPalindrome(ListNode* head) {
        // 方法1. 使用数组
        /*
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        // 判断是否回文
        for(int i=0; i<v.size()/2; ++i){
            if(v[i] != v[v.size()-1-i]){
                return false;
            }
        }
        return true;
        */

        // 方法2. 反转链表
        if(!head || !head->next) return true;
        ListNode* slow = head, * fast = head;
        // 将slow指针移动到链表中间位置
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // 反转后半部分
        ListNode* curNode = slow, *nextNode = slow->next; 
        while(nextNode){
            ListNode* tmp = nextNode->next;
            nextNode->next = curNode;
            curNode = nextNode;
            nextNode = tmp;
        }
        slow->next = nullptr;
        // 开始比较是否相等
        while(head && curNode){
            if(head->val != curNode->val)
                return false;
            head = head->next;
            curNode = curNode->next;
        }
        return true;
    }
};
```