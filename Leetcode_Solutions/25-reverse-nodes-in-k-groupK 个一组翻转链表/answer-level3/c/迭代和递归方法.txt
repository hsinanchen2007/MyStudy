迭代方法：


    struct ListNode* reverseKGroup(struct ListNode* head, int k){
        if (head == NULL || head->next == NULL) {
            return head;
        }
        //创建一个临时头节点，避免链表头节点需要区分处理
        struct ListNode *point = (struct ListNode *)malloc(sizeof(struct ListNode));
        struct ListNode *tmphead = head;
        point->next = head;
        head = point;


        //获取链表节点数量
        int cnt = 0;
        while (tmphead != NULL) {
            cnt++;
            tmphead = tmphead->next;
        }

        int i;
        struct ListNode *prev, *now, *tmp;
        while (point != NULL) {
            //判断剩下的节点数量是否足够
            if (cnt < k) {
                break;
            }

            //指定K个节点逆转
            tmphead = NULL;
            prev = point->next;
            now = point->next->next;
            for (i=0; i<k; i++) {
                prev->next = tmphead;
                tmphead = prev;
                prev = now;

                if (now != NULL) {
                    now = now->next;
                }
            }
            //处理后的prev指针指向第K+1个节点或NULL

            //串联下部分节点：原第1个节点，现第K个节点，指向第K+1个节点或NULL
            point->next->next = prev;

            //暂存第K个节点（尾节点）
            tmp = point->next;

            //串联上部分节点，第一次操作时head指针对应临时节点的后继节点为链表的头节点
            point->next = tmphead;

            //point指针指向第K个节点，作为下一轮K个节点的临时前继节点
            point = tmp;

            //重新计算可用的剩余节点数量
            cnt = cnt - k;
        }
        //释放临时节点
        tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }

递归方法：

    struct ListNode* reverseKGroup(struct ListNode* head, int k){
        int i;
        //判断剩下的节点数量是否足够
        struct ListNode *tmp = head->next;
        for (i=0; i<k-2; i++) {
            tmp = tmp->next;
            if (tmp == NULL) {
                return head;
            }
        }

        //翻转K个节点
        struct ListNode *prev = NULL;
        struct ListNode *now = head;
        struct ListNode *next = head->next;
        for (i=0; i<k; i++) {
            now->next = prev;
            prev = now;
            now = next;

            if (next != NULL) {
                next = next->next;
            }
        }
        //K+1作为新的头节点，递归处理
        head->next = reverseKGroup(now, k);
        return prev;
    }
