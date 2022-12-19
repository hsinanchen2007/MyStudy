### 解题思路
方法一：长度判别法
方法二：快慢指针法（推荐）
![image.png](https://pic.leetcode-cn.com/5c5e26a49f86e50ee786d5050b96b4e14861eb85a5111942519374e97b767dcd-image.png)


### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/*struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* pstLnCur = head;
    int iLength = 0;
    while(NULL != pstLnCur)
    {
        iLength++;
        pstLnCur = pstLnCur->next;
    }

    pstLnCur = head;
    int  i = 0;
    while(i<iLength/2)
    {
        i++;
        pstLnCur = pstLnCur->next; //注意i和pstLnCur节点的关系。每循环一次pstLnCur会指向下一个指针。
    return pstLnCur;

}*/

/* 方法二：快慢指针法 */
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* pstLnFast = head;
    struct ListNode* pstLnSlow = head;

    while((NULL != pstLnFast) && (NULL != pstLnFast->next))
    {
        pstLnFast = pstLnFast->next->next;
        pstLnSlow = pstLnSlow->next;
    }
    return pstLnSlow;  
}
```