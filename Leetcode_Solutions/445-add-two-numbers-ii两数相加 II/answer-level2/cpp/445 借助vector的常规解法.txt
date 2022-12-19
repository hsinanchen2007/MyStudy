### 解题思路
1，将两条链中每个节点的地址分别存在在两个vector容器中；
2，从最后一个节点开始，获取每个节点的值并相加，分为三步：
----a，执行短链长度个循环，将节点值和前一个循环的进位数相加，并获取新的进位数（0或者1）；
----b，执行 （长链长度-短链长度） 个循环，将长链节点的值和前一个循环的进位数相加，并取得新的进位数（0或者1）；
----c，若上一步骤的最后一次循环中的进位数为1，则初始化一个新节点并设置为头结点。
时间复杂度≈O(len_max+len1+len2)；
空间复杂度≈O(len1+len2)；
其中，len_max是两条链中较长链的长度，len1是l1的长度，len2是l2的长度。
![image.png](https://pic.leetcode-cn.com/272227e60686c049c6a59a184f1c12ed0415529ac87cd50997286a176d54cc67-image.png)

### 代码

```cpp
#include <vector>

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1->val == 0)
            return l2;
        if (l2->val == 0)
            return l1;

        vector<ListNode*> addr1, addr2;
        ListNode *p=l1, *q=l2;
        while (p) {
            addr1.push_back(p);
            p = p->next;
        }
        while (q) {
            addr2.push_back(q);
            q = q->next;
        }

        int len1=addr1.size(), len2=addr2.size();
        vector<ListNode*> addr_max = len1>len2?addr1:addr2;
        int len_min = min (len1, len2);
        int len_max = max (len1, len2);
        int diff = len_max-len_min;      
        int flag = 0, preFlag = 0;
        ListNode *res=nullptr, *r; //res需要初始化为空指针，不然没有指向任何空间，调试时会出错。
        for (int i=0; i<len_min; i++) {
            int temp = addr1[len1-1-i]->val + addr2[len2-1-i]->val + preFlag;
            if (temp > 9) {
                temp = temp%10;
                flag = 1;
            }
            r = new ListNode(temp);
            r->next = res;
            res = r;
            preFlag = flag;
            flag = 0;
        }
        for (int i=0; i<diff; i++) {
            int temp = addr_max[diff-1-i]->val+preFlag;
            if (temp > 9) {
                temp = 0;
                flag = 1;
            }
            r = new ListNode(temp);
            r->next = res;
            res = r;
            preFlag = flag;
            flag = 0;
        }
        if (preFlag) {
            r = new ListNode(1);
            r->next = res;
            res = r;
        }
        return res;
    }
};
```