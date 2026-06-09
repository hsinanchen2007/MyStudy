### 解题思路
![leetcode92反转链表2.jpg](https://pic.leetcode-cn.com/7480d5d3953464f26c7326c871da6123edfcb93db7b29287859e5f74cf8bb703-leetcode92%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A82.jpg)

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
    //时间复杂度：O(n)，最差扫描一趟链表
    //空间复杂度：O(1)
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        ListNode * pre = NULL;
        ListNode * cur = head;
        int count = 0;
        ListNode * pM = NULL;
        ListNode * preM = NULL;
        while(cur != NULL )
        {
            ListNode * next = cur->next;
            if(count+1 == m){
                pM = cur;
                preM = pre;
            }

            if(count+1>m && count+1<n){
                cur->next = pre;
            }

            if(count+1 == n){
                pM->next = cur->next;
                if(preM != NULL){  //m == 1
                    preM->next = cur;
                }else{
                    head = cur;
                }
                cur->next = pre;
                break;
            }

            pre = cur;
            cur = next;
            count++;
        }
        return head;
    }
};
```