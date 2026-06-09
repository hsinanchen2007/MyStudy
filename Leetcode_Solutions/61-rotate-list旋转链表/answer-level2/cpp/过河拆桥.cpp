
<![image.png](https://pic.leetcode-cn.com/e4d823425d745cebde430e0571bd0a87e27260377428f2eabe44c97eee967630-image.png){:width="200px"}, ![image.png](https://pic.leetcode-cn.com/b27bc8d5938368f031ae45daf4124ae913b97b817b3f6265e0b7594a098a8cae-image.png){:width="200px"}, ![image.png](https://pic.leetcode-cn.com/e0ea171a4a5abae196bd5610b68fb9605e178a5309152ecfcd57c074fcfef164-image.png){:width="200px"}, ![image.png](https://pic.leetcode-cn.com/398211c82a7fa67d5ecc2a1a14a3baef76b1a73b1a33f689352c972277b54318-image.png){:width="200px"}, ![image.png](https://pic.leetcode-cn.com/d2e53fed93ea5155b349dd4916395808b7dd5368c1f4690e6fd6edbd3aaa3598-image.png){:width="200px"}, ![image.png](https://pic.leetcode-cn.com/f8811b7fd4849c3825ade3fbba07e5d9c3494bcbbc9da3b63edc6c5bb2e47525-image.png){:width="200px"}, ![image.png](https://pic.leetcode-cn.com/ed67b1825ca0de81c207977c70666771b08775cd786f81317265ea17da42f102-image.png){:width="200px"},![image.png](https://pic.leetcode-cn.com/8f96c7a748c5aa0109d3afebd5ab4d14c664f08dfe2e3a4e259da941a8052e35-image.png){:width="200px"},![image.png](https://pic.leetcode-cn.com/7f54f4704d46502d63ee592336fecf5e608c8b29b586e48360226968a141a57c-image.png){:width="200px"}>
>


```
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p = head;
        int len = 1;
        int dis = 0;
        if(!head) return NULL;
        while(p->next) {
            p = p->next;
            len++;
        }
        p->next = head;
        dis = len - (k % len);
        
        while(dis--) {
            p = p->next;
        }
        ListNode *pre = p;
        // 过桥
        p = p->next;
        // 变头
        head = p;
        //拆桥
        pre->next = NULL;
        
        return head;
    }
};
```
