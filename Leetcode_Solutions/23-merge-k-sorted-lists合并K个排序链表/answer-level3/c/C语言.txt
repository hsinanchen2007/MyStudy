方法一、递归(356 ms,9.3 MB)，每次合并两个

    struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
        struct ListNode *curNode1 = NULL;
        struct ListNode *preNode2 = NULL;
        struct ListNode *curNode2 = NULL;

        if (listsSize < 1) {
            return NULL;
        }
        if (listsSize == 1) {
            return lists[0];
        }

        curNode1 = lists[0];
        preNode2 = NULL;
        curNode2 = lists[1];
        while (curNode1 != NULL) {
            while (curNode2 != NULL) {
                if (curNode2->val > curNode1->val) {
                    break;
                }
                preNode2 = curNode2;
                curNode2 = curNode2->next;
            }
            if (preNode2 == NULL) {
                lists[1] = curNode1;
                curNode1 = curNode1->next;
                lists[1]->next = curNode2;
                preNode2 = lists[1];
                continue;
            }
            preNode2->next = curNode1;
            curNode1 = curNode1->next;
            preNode2->next->next = curNode2;
            preNode2 = preNode2->next;
        }
        
        return mergeKLists(&lists[1], listsSize - 1);
    }

方法二、分治（28 ms，9.4 MB）

    struct ListNode* mergeKTwoLists(struct ListNode* lists1, struct ListNode* lists2) {
        struct ListNode *curNode1 = lists1;
        struct ListNode *preNode2 = NULL;
        struct ListNode *curNode2 = lists2;

        while (curNode1 != NULL) {
            while (curNode2 != NULL) {
                if (curNode2->val > curNode1->val) {
                    break;
                }
                preNode2 = curNode2;
                curNode2 = curNode2->next;
            }
            if (preNode2 == NULL) {
                lists2 = curNode1;
                curNode1 = curNode1->next;
                lists2->next = curNode2;
                preNode2 = lists2;
                continue;
            }
            preNode2->next = curNode1;
            curNode1 = curNode1->next;
            preNode2->next->next = curNode2;
            preNode2 = preNode2->next;
        }
        return lists2;
    }

    struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
        struct ListNode *leftList = NULL;
        struct ListNode *rightList = NULL;

        if (listsSize < 1) {
            return NULL;
        }
        if (listsSize == 1) {
            return lists[0];
        }
        if (listsSize == 2) {
            return mergeKTwoLists(lists[0], lists[1]);
        }
        
        leftList = mergeKLists(lists, listsSize / 2);
        rightList = mergeKLists(lists + listsSize / 2, listsSize - listsSize / 2);
        
        return mergeKTwoLists(leftList, rightList);
    }