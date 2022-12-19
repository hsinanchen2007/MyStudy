```
    ListNode* sortList(ListNode* head) {
        auto dummy = ListNode(-1);
        dummy.next = head;
        int len = 0;
        auto cur = dummy.next;
        while(cur){
            ++len;
            cur = cur->next;
        }
        for(int i = 1;i < len;i*=2){//i从1开始，代表每组右边分组的起始下标。如 i = 2,左边组为[0,1],右边组为[2,3]
            cur = &dummy;//每次都从头来一次遍历,分段排序
            for(int j = 0;j + i < len;j += i*2){//间隔是1的话,j需要+2才能到下一组;i=2的话,j+4才能跳到下一组
                auto left = cur->next,right = cur->next;
                for(int k = 0;k < i;++k)
                    right = right->next;//right指向分组的后面一组
                int l = 0,r = 0;
                while(l < i && r < i && right){//&&right是因为后面一组可能不是等长的
                    if(left->val <= right->val){
                        cur->next = left;
                        cur = left;
                        left = left->next;
                        ++l;
                    }
                    else{
                        cur->next = right;
                        cur = right;
                        right = right->next;
                        ++r;
                    }
                }
                while(l < i){//如果是因为右边
                    cur->next = left;
                    cur = left;
                    left = left->next;
                    ++l;
                }
                while(r < i && right){//得判断右边这组遍历完没有,它不一定是i这么长的
                    cur->next = right;
                    cur = right;
                    right = right->next;
                    ++r;
                }
                cur->next = right;//将cur指针指向下一个分组的头部,当然它可能为null
            }
        }
        return dummy.next;
    }
```
