```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// 难点在于random的复制，如果是null还好说，
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 第一遍遍历先把基本结构创建出来，把两个链表（原来的和复制的）的指针和random指针存放在一个vector中
        Node* rp;
        Node* rp1;
        Node* p;
        Node* resultHead=NULL;
        if(!head)
            return resultHead;
        else
            resultHead = new Node(head->val);
        p = head->next;
        rp = resultHead;
        vector<Node*> nRandomHead;
        vector<Node*> nHead;
        vector<Node*> nresultHead;
        nRandomHead.push_back(head->random);
        nHead.push_back(head);
        nresultHead.push_back(resultHead);
        while(p){
            nRandomHead.push_back(p->random);
            nHead.push_back(p);
            rp1 = new Node(p->val);
            nresultHead.push_back(rp1);
            rp->next = rp1;
            rp = rp->next;
            p=p->next;
        }// 基本结构创建完毕
        rp = resultHead;
        int j;
        for(int i=0; i<nRandomHead.size(); ++i){
            if(nRandomHead[i]==NULL)
                continue;
            else{
                for(j=0; nRandomHead[i]!=nHead[j]; ++j);
                nresultHead[i]->random = nresultHead[j];
            }
        }
        return resultHead;
    }
};
```
