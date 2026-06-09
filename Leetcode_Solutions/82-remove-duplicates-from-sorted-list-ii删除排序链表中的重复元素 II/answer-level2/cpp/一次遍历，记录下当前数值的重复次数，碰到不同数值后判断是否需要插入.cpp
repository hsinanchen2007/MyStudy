遍历链表，设置一个记录当前可能插入的节点的指针，并记录下当前可能插入的节点数值重复的次数。
当遍历到的节点数值与当前节点不同或者没有后续的时候，根据重复次数，判断当前节点是否要插入到数据结果的尾部。



ListNode* deleteDuplicates(ListNode* head) {
    if (head != nullptr && head->next) {
        ListNode *outputListHead = nullptr;
        ListNode *outputListTail = nullptr;
        ListNode *currentValueNode = head;
        ListNode *currentNode = head;
        int repetionCountOfCurrent = 0;
        while (currentNode) {
            ListNode *currentNext = currentNode->next;
            if (currentNext == nullptr || currentNext->val != currentValueNode->val) {
                //插入结果链表
                if (repetionCountOfCurrent == 0) {
                    //前一个数值没有重复的时候，才加入结果链表
                    if (outputListHead == nullptr) {
                        outputListHead = currentValueNode;
                    }
                    if (outputListTail == nullptr) {
                        outputListTail = currentValueNode;
                    }
                    else
                    {
                        outputListTail->next = currentValueNode;
                        outputListTail = outputListTail->next;
                    }
                }
                //重新开始当前数值的计数
                currentNode = currentNext;
                //刷新新的当前数值
                currentValueNode = currentNode;
                repetionCountOfCurrent = 0;
            }
            else
            {
                //移动到下一个节点。
                repetionCountOfCurrent++;
                currentNode = currentNext;
            }
        }
        if (outputListTail) {
            outputListTail->next = nullptr;
        }
        return outputListHead;
    }
    return head;
}
