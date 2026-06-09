    ListNode* deleteDuplicates(ListNode* head) {
        auto h = new ListNode(-1);//添加头结点
        h->next = head;
        auto pre = h,p = pre->next;//pre指向无重复的最后一个数 p为遍历节点
        while(p){
            while(p->next&&p->val==p->next->val) p = p->next;//p与后不同时退出
            if(pre->next==p) pre = p, p = p->next;//表示p是无重复元素，更新无重复数 pre = p 
            else p = p->next,pre->next = p;//p是重复元素,[pre->next,p]全重复 跳过这段即可
        }
        return h->next;
    }