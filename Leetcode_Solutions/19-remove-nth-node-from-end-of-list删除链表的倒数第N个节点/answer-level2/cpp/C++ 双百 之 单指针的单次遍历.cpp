**解题思路:**
- 写在**递归调用之后**的代码可以类比为栈,一次次递归就相当于push,最后会**先执行最外层函数**,尔后一层一层地执行已递归但还没有执行的函数,这里我称之为"**回溯**"
- 指定一个指针,让它**递归到顶**,然后利用"回溯",在**层层执行代码**的时候**让参数层层递减**,递减到0时所在的节点就是目标,于是我们再递归一层,让参数减到`-1`,此时就可以执行`node->next = node->next->next`
- 容易发现,上述方法不能删除头结点,于是**人为加一个辅助节点作为头结点**,以便于递归后的删除节点操作,返回时`return auxil->next;`
```

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* auxil=new ListNode(0);
        auxil->next=head;  //如果删除的是头结点，不能用递归统一处理，就人为加一个prior便于处理
        removeNthFromEnd_Solition(auxil,n);
        return auxil->next;
    }
    void removeNthFromEnd_Solition(ListNode*& p,int& target){
        if(p){
            removeNthFromEnd_Solition(p->next,target); // 递归到顶
            if(--target==-1)        // 递归后回溯，target==0的节点是要删除的节点
                p->next=p->next->next;  // 因此target==-1时的节点是待删除节点的prior
        }
    }
};
```
