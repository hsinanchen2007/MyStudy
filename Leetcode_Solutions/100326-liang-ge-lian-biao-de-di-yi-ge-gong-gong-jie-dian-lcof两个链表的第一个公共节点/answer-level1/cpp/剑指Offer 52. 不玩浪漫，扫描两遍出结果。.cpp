![image.png](https://pic.leetcode-cn.com/433b9f0fa434a12807284c0c4054a4f65ef540cc016ddb8d4ccf553169e2e1df-image.png)

### 解题思路
### 第一遍扫描：找出长度差值
两个链表同步往后，如果发现指针相同，那直接return，就完了。
如果一直没找到，并且短的那个到达了末尾。------ 让长的继续跑，并记录次数step。
等长的链表指针也到达了，末尾，就得出了两个链表的差值（记为step）。

### 第二遍扫描：让长的先跑
**长的先跑step步。**
然后**同步移动**，如果这样还是找不到，那铁定找不到了。 

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int step = 0;
        ListNode* pa = headA;
        ListNode* pb = headB;
        while(pa&&pb){
            if(pa == pb) return pa;
            pa = pa->next;
            pb = pb->next;
        }
        if(pa){ // pa不为空，说明pa所在链表要长一点。
            while(pa){ // 看看pa链表要比pb长多少
                step++; 
                pa = pa->next;
            }
            pb = headB; // 两个链表都回到各自起点
            pa = headA;
            for(int i=0; i<step; i++){ // pa先跑step步
                pa = pa->next;
            }
            while(pa&&pb){ // 然后同步跑
                if(pa == pb) return pa;
                pa = pa->next;
                pb = pb->next;
            }
            return NULL;
        }
        if(pb){
            while(pb){
                step++;
                pb = pb->next;
            }
            pb = headB;
            pa = headA;
            for(int i=0; i<step; i++){
                pb = pb->next;
            }
            while(pa&&pb){
                if(pa == pb) return pb;
                pa = pa->next;
                pb = pb->next;
            }
            return NULL;
        }
        return NULL;
    }
};
```
### 后记
关键是单链表的性质，一旦相交，后面的都一样，也就是说相交的单链表一定是个Y字型，顶多是个V型，反正绝不可能是X型。
![image.png](https://pic.leetcode-cn.com/beba02d920a2344fd780088b307f797d6c7912c9cd7b80b4bde9296f49d90269-image.png)

上图中，我们从圆圈处开始跑，如果有交点，肯定能找到。

问个问题： 两个长度相同的单链表，如何找公共节点？
答案：直接同步遍历一遍，找到就有，找不到就肯定没有。