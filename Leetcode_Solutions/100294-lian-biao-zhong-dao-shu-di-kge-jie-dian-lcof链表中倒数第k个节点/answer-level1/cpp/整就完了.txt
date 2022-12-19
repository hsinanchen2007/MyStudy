### 解题思路
此处撰写解题思路

1、先算出链表的长度len；
2、倒数第k个元素等于 正数第 len-k+1（len-(k+1)） 个元素
3、比如1~9（正数从第1开始，不考虑0，考虑0你就懵了）一共9个数，倒数第三个数是数字7，数字7是正数第7个位置，位置7 = 9 - 3 + 1
4、上面反应一会就明白了
5、让头节点跑（len-k+1）次，就到了那个位置

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

        ListNode* cur = head;
        int count = 0;
        while(cur != NULL)
        {
            count++;
            cur = cur->next;
        }
        for (int i =0; i < count - k; i++)
        {
            head = head->next;
        }
        return head;
    }
};
```