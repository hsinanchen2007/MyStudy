方法一 利用栈
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode *> vA,vB;
        ListNode *res=headA,*ans=headB;
        int lenA=0,tmp=0;
        while(headA!=NULL||headB!=NULL){
            if(headA!=NULL){
                vA.push(headA);
                headA=headA->next;
                lenA++;
            }
            if(headB!=NULL){
                vB.push(headB);
                headB=headB->next;
            }
        }
        while(!vA.empty()&&!vB.empty()){
            if(vA.top()!=vB.top()) break;
            tmp++;
            vA.pop(),vB.pop();
        }
        if(tmp==0) return NULL;
        for(int i=0;i<lenA-tmp;i++) res=res->next;
        return res;
    }
};
```
方法二、利用set
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> st;
        while(headA!=NULL){
            st.insert(headA);
            headA=headA->next;
        } 
        while(headB!=NULL){
            if(st.count(headB)) return headB;
            headB=headB->next;
        }
        return NULL;
    }
};
```
方法三
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int tmp=0;
        ListNode *res=headA,*ans=headB;
        while(headA!=NULL&&headB!=NULL){
            headA=headA->next;
            headB=headB->next;
        } 
        while(headA!=NULL){
            headA=headA->next;
            res=res->next;
        }
        while(headB!=NULL){
            headB=headB->next;
            ans=ans->next;
        }
        while(res!=NULL||ans!=NULL){
            if(res==ans) return res;
            res=res->next;
            ans=ans->next;
        } 
        return NULL;
    }
};
```
方法四 官方的方法三
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //if (headA == NULL || headB == NULL) return NULL;
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA == NULL ? headB : pA->next;
            pB = pB == NULL ? headA : pB->next;
        }
        return pA;
    }
};
```

