
对于这道题，我的第一直觉是利用递归来按照逆序获取链表的尾部。
示意图如下：
![無題.png](https://pic.leetcode-cn.com/9f5c0eb53b64fd6d4ea19c27e27926bacea3e0968c4d23ca9316b307beb8d3d5-%E7%84%A1%E9%A1%8C.png)
欢迎讨论
```
class Solution {
public:
    ListNode* node;                         //新建一个节点用来保存当前排序进度
    void reorderList(ListNode* head) {
        node=head;                          //初始化进度节点为头节点
        getorder(head);
    }

    void getorder(ListNode* head){
        if(head==nullptr)return;
        getorder(head->next);               //递归，从后往前获取尾部节点
        if(node->next==nullptr)return;      //排序完成时结束。
        ListNode* tmp=node->next;
        node->next=head;
        node->next->next=tmp;
        node=node->next->next;
        if(node!=nullptr && (node->next==node || node->next->next==node))node->next=nullptr;
                                            //判断是否完成排序。
    }
};
```
