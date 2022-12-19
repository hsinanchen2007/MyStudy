        node->val=node->next->val;
        node->next=node->next->next;
        // 或者直接一句 *node=*(node->next);