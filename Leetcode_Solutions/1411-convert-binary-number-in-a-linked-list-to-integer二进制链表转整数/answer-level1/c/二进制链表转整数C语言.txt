### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/6100b8384c4586e4b91f510ccea976f1af7539de40769766e253701fad21adb7-image.png)

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 方法一：正常的二进制转十进制方法，2的次幂。 */
int getDecimalValue(struct ListNode* head){
    struct ListNode* pstLnCur = NULL;
    int iValue = 0;
    int iSum = 0;
    int iLength = 0;
    pstLnCur = head;

    while(NULL != pstLnCur)
    {
        iLength++;
        pstLnCur = pstLnCur->next;
    }

    iValue = 1;
    pstLnCur = head;
    while(NULL != pstLnCur)
    {
        if(1 == pstLnCur->val)
        {
            iSum += (pow(2, (iLength-iValue))); //原出错:(2^(iLength-iValue));c语言不支持。
            //printf("iSum=%d ", iSum);
        }
        iValue++;
        pstLnCur = pstLnCur->next;
    }

    return iSum;
}

/* 方法二：位运算法 */
/*思路：位运算
每取 1 位数字，将当前所有数位 左移 1 位；
通过位运算 或 将新取出数字(0/1)存入最低位。*/
/*int getDecimalValue(struct ListNode* head){
    int iValue = 0;
    struct ListNode * pstLnCur = head;

    while(NULL != pstLnCur)
    {
        iValue = (iValue<<1) | (pstLnCur->val); //原计算完数左移一位，最低位或上新取出。
        pstLnCur = pstLnCur->next;
    }
    return iValue;
}*/

```