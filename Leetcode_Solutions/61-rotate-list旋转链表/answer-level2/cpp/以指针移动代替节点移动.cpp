### 解题思路
首先明确几点：
1. 链表右移相当于头节点左移，链表左移相当于头指针右移，题目要求把链表右移k位，那么取而代之我们可以把链表头指针左移k位；
2. 对于链表而言，寻找后继很容易，但是寻找祖先不方便；
3. 如果我们已知链表的总节点数node_num，那么我们可以把头指针左移k位（这里提前执行k = k % node_num以消除不必要的循环）的操作转化为右移node_num-k。
这样下来题目的解决就比较简单了：
1. 统计链表总节点数；
2. k = node_num - k % node_num;
3. 执行头指针右移k位；
4. 将新头指针与前继节点断开，将链表尾连接到旧头节点上；
5. 返回新头指针。
已知的不足之处：
1. 从上面的步骤可以发现，统计链表节点数目的过程和执行指针右移的过程都从head开始对一系列节点进行了重复的遍历，这里有待进一步优化，但是暂时不知道如何优化。

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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *new_head = NULL, *pos = head;
        //先统计链表节点总数
        int node_num = 0;
        while(pos != NULL){
            node_num ++;
            pos = pos->next;
        }
        if(node_num == 0 || k % node_num == 0) return head;

        //右移k位和左移node_num-k位一样，更新k后执行左移
        k = k % node_num;
        k = node_num - k;
        pos = head;
        while(pos->next != NULL){
            if(k == 1){ //下一个节点就是新头节点
                new_head = pos->next;
                pos->next = NULL;
                pos = new_head;
            }
            //pos右移继续寻找new_head和链表末尾
            k --;
            if(pos->next == NULL) break;
            pos = pos->next;

        }
        pos->next = head; //链接首尾
        return new_head;

    }
};
```