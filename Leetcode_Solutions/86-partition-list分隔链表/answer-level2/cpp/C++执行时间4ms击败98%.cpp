思想很简单，从前往后遍历，遇到满足条件的(val>=x)则将其在链表中移除，然后将该结点放到链表的尾部去，遇到不满足条件的就依次往下遍历，但是不是很明白为什么
采用这种思路占用的内存很大，实验占了8Mb,理论上这种思路应该比那种重新创建新链表的占用内存少的，如果有明白的朋友还希望多多指点。
```
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return nullptr;
        ListNode* pTail = head;       //找到链表的尾节点
        while(pTail->next){
            pTail = pTail->next;
        }
        ListNode* pHead = new ListNode(x-1);   //类似于哨兵作用(首部哨兵)
        ListNode* pTail_set = new ListNode(x-1);  //设定尾部哨兵
        pTail->next = pTail_set;
        pTail_set->next = nullptr;
        pTail = pTail_set;
        pHead->next = head;
        ListNode* pTailCopy = pTail;
        ListNode* pNode = head;
        ListNode* pPrev = pHead;
        while(pNode!=pTail){
            if(Judge_Node(pNode,x)){
                pPrev->next = pNode->next;
                pTailCopy->next = pNode;
                pNode->next = nullptr;
                pTailCopy = pNode;
                pNode = pPrev->next;
            }
            else{
                pPrev = pNode;
                pNode = pNode->next;
            }
        }
        pPrev->next = pTail->next;
        ListNode* pHeadReal = pHead->next;
        delete pHead;
        delete pTail;
        pTail = nullptr;
        pHead = nullptr;
        return pHeadReal;
    }
private:
    bool Judge_Node(ListNode* pNode,int x){     //结点数值val大于等于x则返回true
        if(!pNode) return false;
        return (pNode->val>=x)?true:false;
    }
};
```
