方法1：增加一个哑结点；
找到比x大的第一个节点的前一个节点，代码中p节点；
再从该节点的后一个节点开始，依次将比x小的节点用头插法插入p节点之前。
```
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *H = new ListNode(0);
        H -> next = head;
        ListNode *p = H;
        while (p -> next && p -> next -> val < x){
            p = p -> next;
        }
        ListNode *q = p -> next;
        while (q && q -> next){
            if (q -> next -> val < x){
                ListNode *nex = q -> next -> next;
                q -> next -> next = p -> next;
                p -> next = q -> next;
                q -> next = nex;
                p = p -> next;
            }
            else
                q = q -> next;
        }
        ListNode *newHead = H -> next;
        delete H;
        return newHead;
    }
};
```

方法2：参考的官方题解。
bigger链接>=x的节点，smaller链接<x的节点；
将smaller链接bigger中第一个比x大的节点；
smaller指向空。
```
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *bigger = new ListNode(0);
        ListNode *smaller = new ListNode(0);
        ListNode *res = smaller;
        ListNode *junction = bigger;
        while (head){
            if (head -> val < x){
                smaller -> next = head;
                smaller = smaller -> next;
            }
            else{
                bigger -> next = head;
                bigger = bigger -> next;
            }
            head = head -> next;
        }
        bigger -> next = NULL;
        smaller -> next = junction -> next;
        return res -> next;
    }
};
```

方法3：类似方法2，对哑结点的使用很好。
```
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *H = new ListNode(0);
        H -> next = head;
        ListNode *tmp = new ListNode(0);
        ListNode *cur = H;
        ListNode *p = tmp;

        while (cur -> next){
            if (cur -> next -> val < x){
                p -> next = cur -> next;
                cur -> next = cur -> next -> next;
                p = p -> next;
            }
            else
                cur = cur -> next;
        }
        p -> next = H -> next;
        ListNode *res = tmp -> next;
        delete tmp;
        return res;

    }
};
```
方法4：用数组做，思想同方法2。
```
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head -> next == NULL)
            return head;
        vector<int> small, big;
        ListNode *p = head;

        while (p){
            if (p -> val < x)
                small.push_back(p -> val);
            else
                big.push_back(p -> val);
            p = p -> next;
        }
        p = head;
        for (int i = 0; i < small.size(); i++){
            p -> val = small[i];
            p = p -> next;
        }
        for (int i = 0; i < big.size(); i++){
            p -> val = big[i];
            p = p -> next;
        }
        return head;
    }
};
```

