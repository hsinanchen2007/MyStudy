![image.png](https://pic.leetcode-cn.com/1d24bab187ebb86f64092b2dcfcfcba640bd87fb43e17a71d1e24ba366fbffa5-image.png)

### 解题思路
1. 遍历一下，取总长度`size`；
2. 计算每一段的节点数`subCnt = 基础节点数subSize + 补充节点数`
   其中，基础节点数`subSize = size / k`；  
   剩余节点数`modSize = size % k`，将剩余节点数一个一个取出来，作为`补充节点`加到每一段中，取完为止。所以补充节点数为1或者为0。  
   即：  
   ```c  
   subCnt = subSize + ((modSize > 0)?1:0);   
   modSize--;
   ```
3. 有了每段的节点数，剩下的工作就是遍历整个链表，按节点数拆分保存即可。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize){
    if(k == 0) {
        *returnSize = 0;
        return NULL;
    }
    struct ListNode** ret = (struct ListNode**)malloc(sizeof(struct ListNode*) * k);
    *returnSize = k;
    if(k == 1) {
        *ret = root;
        return ret;
    }

    // 总长度
    int size = 0;
    struct ListNode* p = root;
    while(p != NULL){
        size++;
        p = p->next;
    }

    // 分段基础长度
    int subSize = size / k;
    // 剩余的节点数
    int modSize = size % k;
    
    p = root;
    for(int i=0; i<k; i++) {
        // 如果剩余节点数不为0，每段增加1个节点，这个节点是从剩余节点数中取出来的，取完为止
        int subCnt = subSize + ((modSize > 0)?1:0);
        modSize--;
        // 每段总要有1个节点，可能为空节点
        if(subCnt == 0) subCnt = 1;
        ret[i] = p;
        struct ListNode* subTail = p;
        while(subCnt > 0) {
            subTail = p;
            if(p != NULL) {
                p = p->next;
            }
            subCnt--;
        }
        if(subTail != NULL) {
            subTail->next = NULL;
        }
    }

    return ret;
}
```