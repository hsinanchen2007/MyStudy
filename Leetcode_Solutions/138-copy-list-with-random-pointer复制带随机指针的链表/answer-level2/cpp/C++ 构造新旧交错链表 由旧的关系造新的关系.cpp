```
    Node* copyRandomList(Node* head) {//即要求再创一个链表，结构与其相同
        if(!head) return NULL; 
        //创建相邻节点使得新旧交错
        auto oldp = head;
        while(oldp){
            oldp->next = new Node(oldp->val,oldp->next,NULL);//创建oldp的值的副本，然后插入oldp的后面
            oldp = oldp->next->next;
        }
        oldp = head;
        while(oldp){//因为新节点在旧节点之后，所以借助旧节点之间的关系，连接新节点的random域
            if(oldp->random)//旧节点的random不空时才赋值
                oldp->next->random = oldp->random->next;
            oldp = oldp->next->next;
        }
        auto newh = head->next,newp = newh;
        oldp = head; 
        while(oldp){//将新节点的next域相连
            oldp->next = oldp->next->next;
            if(oldp->next) newp->next = oldp->next->next;
            oldp = oldp->next;
            newp = newp->next;
        }
        return newh;
    }
```
