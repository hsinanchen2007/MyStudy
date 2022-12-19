### 解题思路
1.链表排序和数组排序存在差异，数组可以随机访问，链表只能顺序访问。
2.时间复杂度较低的排序方法中，归并排序并不需要随机访问的条件。
3.虽然链表不可以随机访问，但由于可以更改链表节点之间的连接顺序，所以在归并过程中不需要开辟额外的空间，而数组归并排序时要额外开辟空间暂存排序结果。
4.数组和链表不同，数组各元素之间没有联系，使用index可以明确划分边界，而链表各元素之间存在联系，特别是在归并排序合并的过程中链表元素之间的联系会显得混乱，所以更要明确划分边界。我们在将一个链表二分之后，左侧的部分结尾要end->next=NULL，明确边界。
5.在递归过程中设现在正处理第i层左侧排序，左侧头指针为head,现进入第i+1完成该左侧排序，但排好序之后头指针发生了变化，但回到第i层时，head仍然是原来的head，这里就出现了问题，所以要返回更新后的头指针覆盖head.
6.合并过程中三个指针，leftHead,rightHead,temp；leftHead和rightHead指向当前左右部分比较元素，temp不断串联左右链表中的元素。与数组不同的是，一旦有一个链表排序完，另一个链表可以直接连接到temp后面不必在一个一个元素的拼接。
7.归并排序递归过程：
1）确定递归边界；
2）左侧排序
3）右侧排序
4）对排好序的左右部分合并。

### 代码

```cpp
class Solution {
public:
    ListNode *mergeSort(ListNode* leftHead,int length){
        if(!leftHead->next)return leftHead;
        ListNode * leftTail=leftHead;
        //从中间cut,左侧的部分结尾的next改NULL,初始已经指向head了，所以i初始为1；
        for(int i=1;i<length/2;i++){
            leftTail=leftTail->next;
        }
        ListNode *rightHead=leftTail->next;
        leftTail->next=NULL;//cut
        //sort left part
        leftHead=mergeSort(leftHead,length/2);
        //sort right part
        rightHead=mergeSort(rightHead,length-length/2);
        //merge
        ListNode *temp=new ListNode,*head;
        head=temp;

        while(leftHead!=NULL &&rightHead!=NULL){
                if(leftHead->val<rightHead->val){
                    temp->next=leftHead;
                    temp=leftHead;
                    leftHead=leftHead->next;
                }
                else{
                    temp->next=rightHead;
                    temp=rightHead;
                    rightHead=rightHead->next;
                }
        }
        if(leftHead==NULL)temp->next=rightHead;
        else temp->next=leftHead;
        
        ListNode *p=head->next;
        delete head;//release space
        return p;
    }

    ListNode* sortList(ListNode* head) {
        if(!head)return head;
        int cnt=0;
        for(auto *p=head;p!=NULL;p=p->next)cnt++;
        return mergeSort(head,cnt);
    }
};
```