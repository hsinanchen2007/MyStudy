利用栈进行反转
第一步，寻求到第m-1个节点，第m个节点，第n个节点
第二步，从第m个到第n个节点的值压入进栈
第三步，然后逐个新建节点，值出栈
第四步，考虑特殊情况，如果原列表长度为1或者空，或者m=n则直接返回链表自身。
```C++ []
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        stack<int> s ;
        ListNode* tmp = head;
        ListNode* newhead = head;
        ListNode* pre_start = NULL;
        ListNode* start = NULL;
        ListNode* end = NULL;
        int count = 0;
        if (head==NULL || head->next==NULL || m == n) return head;
        while(count <=n){
            count++;
            if(count >= m && count<= n ) {
                s.push(tmp->val);
                }//m-n之间的节点入栈
            if(count == m-1) {
                pre_start = tmp;//保留第m-1个节点，如果m为1,那么修改新的链表头
                
                }
            if(count == m) {
                start = tmp;//保留第m-1个节点                
                
                }
            if(count == n){
                end = tmp;//保留第n个节点
                
                break;
            }    
            tmp = tmp->next;
        }
        if(end->next!=NULL) tmp = tmp->next;//如果第n个节点不是最后一个
        while(!s.empty()){
            if(pre_start==NULL){ 
                pre_start = new ListNode((int)s.top());
                newhead = pre_start;
                s.pop();
            }
            start = new ListNode((int)s.top());
            pre_start->next = start;
            pre_start = start;
            s.pop(); 
        }
        if(end->next!=NULL) start->next = tmp;//如果第n个节点不是最后一个
        return newhead;
    }
};
```
```Java []
public ListNode reverseBetween(ListNode head, int m, int n) {
        Stack s = new Stack();
        ListNode tmp = head;
        ListNode newhead = head;
        ListNode pre_start = null;
        ListNode start = null;
        ListNode end = null;
        int count = 0;
        if (head==null || head.next==null || m == n) return head;
        while(count <=n){
            count++;
            if(count >= m && count<= n ) {
                s.push(tmp.val);//m-n之间的节点入栈
                }
            if(count == m-1) {
                pre_start = tmp;//保留第m-1个节点，如果m为1,那么修改新的链表头
                //System.out.println(count+":\t"+pre_start.val);    
                }
            if(count == m) {
                start = tmp;//保留第m-1个节点                
                //System.out.println(count+":\t"+start.val);    
                }
            if(count == n){
                end = tmp;//保留第n个节点
                //System.out.println(count+":\t"+end.val);    
                break;
            }    
            tmp = tmp.next;
        }
        if(end.next!=null) tmp = tmp.next;//如果第n个节点不是最后一个 
        //System.out.println(count+":\t"+tmp.val);  
        while(!s.empty()){
            if(pre_start==null){ //如果从第一个开始反转，则newhead应该是个新的头，栈顶值
                pre_start = new ListNode((int)s.peek());
                newhead = pre_start;
                s.pop();
            }
            start = new ListNode((int)s.peek());//start则是开始反转的值，如果从第一个反转，则start从第二个开始
            pre_start.next = start;
            pre_start = start;
            s.pop(); 
            //System.out.println(count+":\t"+start.val);    
        }        
        if(end.next!=null) start.next = tmp;
        /*
        while(tmp1!=null){
            System.out.println(tmp1.val);
            tmp1 = tmp1.next;
        }
        */
        return newhead;
    }
```

