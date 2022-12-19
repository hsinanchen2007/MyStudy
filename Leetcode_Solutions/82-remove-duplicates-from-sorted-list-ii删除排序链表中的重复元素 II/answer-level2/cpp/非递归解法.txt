
![捕获.PNG](https://pic.leetcode-cn.com/339fdd72359ccccf05e15f2b7c899491071ca865a8f7aed9229f7c84e5cd5180-%E6%8D%95%E8%8E%B7.PNG)

 ListNode* deleteDuplicates(ListNode* head) {
           if(!head || !head->next)
               return head;

           ListNode *p = head;
           ListNode *q = head->next;
           ListNode *he = new ListNode(0);
           ListNode *hp = he;
           he->next = head;

           while(q){

               if(p->val != q->val){
                   hp->next = p;
                   hp = p;
                   p = q;
                   q = q->next;
               }
               //aa^
               else if(!q->next){
                   hp->next = NULL;
                   break;
               }
               //aaa^
               else if(q->next->val == p->val && !q->next->next){
                   hp->next = NULL;
                   break;
               }
               //aab^
               else if(q->next->val != p->val && !q->next->next){
                   hp->next = q->next;
                   printList(hp);
                   break;
               }
               //aaab
               else if(q->next->val == p->val && q->next->next->val != p->val){
                   p = p->next;
                   q = q->next;

               }//aabc
               else{
                   p = q->next;
                   q = p->next;
               }

           }
           return he->next;
       }