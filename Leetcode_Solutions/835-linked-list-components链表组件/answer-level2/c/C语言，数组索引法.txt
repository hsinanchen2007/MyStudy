![image.png](https://pic.leetcode-cn.com/bf277c56b1b6f3db3e1574b06c0303c1c55d218daed11c812caba8d9f9825e42-image.png)

### 解题思路

题目的核心在于，**查找链表节点的值是否在集合G中存在**，如果每次都去遍历G，那遍历次数太大了。  
好在下面这几个条件把数据数量和取值范围划定了，这就好办了。  

- N 是给定链表 head 的长度，1 <= N <= 10000。
- 链表中每个结点的值所在范围为 [0, N - 1]。
- 1 <= G.length <= 10000
- G 是链表中所有结点的值的一个子集。  

把 **遍历操作** 转换为 **直接用索引访问数组**。定义一个10000个元素的数组`indexG`，为集合G中值作为下标的数组元素设置标记（比如`1`）。要查找链表中的值是否在G中存在，只要直接用链表中的值作为数组下标直接访问数组元素`indexG[x]`，看对应数组元素是否设置了标记即可。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int numComponents(struct ListNode* head, int* G, int GSize){
    #define NUM_SIZE 10000
    int* indexG = (int*)malloc(sizeof(int)*NUM_SIZE);
    memset(indexG, 0, sizeof(int)*NUM_SIZE);

    for(int i=0; i<GSize; i++) {
        indexG[G[i]] = 1;
    }

    int ret = 0;
    int compBegin = 0;  // 组件开始标记
    struct ListNode* p = head;
    while(p != NULL) {
        if(indexG[p->val] == 1) {
            // 链表元素在G中存在
            if (compBegin == 0) {
                // 组件开始
                compBegin = 1;
                // 组件个数增加
                ret++;
            }
        } else {
            if (compBegin == 1) {
                // 组件结束
                compBegin = 0;
            }
        }
        p = p->next;
    }

    free(indexG);
    return ret;
}
```