### 解题思路
![屏幕截图(3).png](https://pic.leetcode-cn.com/78daf0c045e7397abf038f0e15b026b3046b31913fed223de1cad414bb30ce30-%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE\(3\).png)
思路就是从头开始遍历链表，用0~20001的数组作散列表，每次出现个数就在数组对应的下标上+1。举例：比如每出现数字17，对应下标的数组array[17]就自增1。所以当出现第二个17的时候，array[17]就会变成2，此时就表明需要删掉这个17。以此类推
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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(head == NULL || head -> next == NULL)
        {
            return head;
        }
        int check[20001] = {0};        //散列表
        ListNode *pre = head;
        ListNode *r = head -> next;

        ++check[head -> val];          //头指针指向的先+1
        while(r != NULL)
        {
            ++check[r -> val];         //对应下标数组加1
            if(check[r -> val] > 1)    //如果大于1，说明重复，执行删除操作
            {
                pre -> next = r -> next;
                ListNode *de = r;
                r = r -> next;
                delete de;
                continue;              //注意当执行删除操作后要跳过后面的往前进一步的语句
            }                          //因为执行删除操作时r已经往前走一步，需要先判断这时数字是否重复
            pre = r;
            r = r -> next;
        }
        return head;
    }
};
```