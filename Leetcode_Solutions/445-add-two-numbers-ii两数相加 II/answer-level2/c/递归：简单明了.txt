
- 1、通过计算长度，获取较长的单链表
- 2、每一位的计算结果要加上上一位的进阶值
- 3、最高位需要单独计算
- 4、难点在于，通过长度判断是否是相同的位置
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getListLen(struct ListNode* lst){
    struct ListNode* tmp = lst;
    int lenth = 0;
    while(tmp != NULL){
        lenth ++;
        tmp = tmp -> next;
    }
    return lenth;
}
//默认l1是较长的单链表
int getCarryByPos(struct ListNode* l1, int len1, struct ListNode* l2, int len2){
    if(len1 == 0){
        return 0;
    }
    // l1 l2使用局部变量，不改变原指针
    struct ListNode* tmp1 = l1;
    struct ListNode* tmp2 = l2;
    if(len1 == len2){
        //加上进阶值
        int val = tmp1 -> val + tmp2 -> val + getCarryByPos(tmp1 -> next, len1 -1, tmp2 -> next, len2 - 1);;
        if(val > 9){
            val =  val % 10;
            tmp1 -> val = val;
            return 1;
        }else{
            tmp1 -> val = val;
            return 0;
        }
    }else{
        int val = tmp1 -> val + getCarryByPos(tmp1 -> next, len1 -1, tmp2, len2);;
        if(val > 9){
            val =  val % 10;
            tmp1 -> val = val;
            return 1;
        }else{
            tmp1 -> val = val;
            return 0;
        }
    }
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    //是的l1是较长的链表
    int len1 = getListLen(l1);
    int len2 = getListLen(l2);
    if(len1 < len2){
        struct ListNode* tmp = l1;
        l1 = l2;
        l2 = tmp;
        int tmpLen = len1;
        len1 =  len2;
        len2 = tmpLen;
    }
    //获取最高位置的进阶值
    int carry = getCarryByPos(l1, len1, l2, len2);
    //如果进阶，则最高位进一，否则返回l1
    if(carry == 1){
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node -> val = carry;
        node -> next = l1;
        return node;
    }else{
        return l1;
    }
}
```
