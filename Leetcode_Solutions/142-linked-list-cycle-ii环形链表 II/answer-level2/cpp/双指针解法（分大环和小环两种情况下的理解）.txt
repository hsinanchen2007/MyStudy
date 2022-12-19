```
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast == NULL){
                return NULL;
            }
            else{
                slow = slow->next;
                fast = fast->next;
                if(slow == fast){
                    ListNode *p = head;
                    ListNode *q = fast;
                    while(p != q){
                        p = p->next;
                        q = q->next;
                    }
                    return p;
                }
            }
        }
        return NULL;
    }
};
```

# **解题思路：**
假设非环部分的长度为F，环部分的长度为C。

快慢指针同时从链表头出发，快指针每次走2步，慢指针每次走1步。

快慢指针最终肯定会在环中某个点相遇，我们设这个点为h点。

 
**（1）**
假设这个环很大，大到慢指针达到入环点的时候，快指针都没有绕环一圈。

那么此时快指针仅在环内走了F个结点，并且假设此时距离入环点还有G个结点。

那么如果慢指针在入环点接着走，走G个结点，那么快指针就走了2G个结点。

因为原本快指针距离入环点只差G个结点，现在走了2G个，那就是过了入环点，然后再走G个点，所以快指针现在距离入环点差的结点数变为F了（环的长度=F+G，走了G就剩F了）。

恰好，头结点到入环点的距离也是F。

所以两个慢指针分别从头结点和现在快指针所在的位置出发，那么两个慢指针相遇的时候，就是入环处了。

 
**（2）**
现在我们再来假设这个环很小，小到他们在h点相遇的时候，快指针已经绕环好多圈了。

假设他们相遇的时候，h点前面有a个结点，h点后面又b个结点，那么慢指针就走过了F+a个结点，而快指针就走过了F+a+k*(a+b)

因为快指针是慢指针速度的两倍，所以2*(F+a) = F + a + k*(a+b)

我们将这个式子化简一下得：F = b + (k-1)*(a+b)

这个式子意味着，如果有两个指针p和q，分别从头结点和h点出发，并且他们速度都是每次走一步。

那么，当p走了F个结点的时候，q会绕环(k-1)圈后回到h点，并且再向前走b个点。这就是这条等式的意义。

然后你就会发现，p和q这时候都会处于入环点。（因为p在头结点出发，走F个点就到入环点；而q从h点出发，走b个点就到入环点。）

也就是说，在环很小的情况下，也只需要设置两个慢指针分别从头结点和h点出发，就能找到入环点了。