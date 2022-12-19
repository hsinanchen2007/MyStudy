### 思路一
递归法
1. 若`child`为`nllptr`，将指针移向`next`节点
2. 若`child`不为空，进入递归，传入头节点（即，`child`的第一位）
3. 连接子链表的尾端和父节点的下一节点。
-  用`nextnode`记录有`child`的节点的下一个节点，用来连接在子链表的尾端
- 通过判断到达链表尾端时，`nextnode`是否为`nullptr`，若是，则该尾端就是第一级链表的尾端，若不是，该尾端就是子链表的尾端。（注意使用`nextnode`连接子链表后，需要将`nextnode`清空，否则会重复连接子链表）
- `prevnode`用来记录`temp`的前一个节点，当`temp`到尾端时为`null`，这时用`prevnode`来连接`nextnode`。
### cpp代码+注释
```
class Solution {
public:
    Node* flatten(Node* head) {
        Node *temp = head;
        Node *nextnode = nullptr;
        Node *prevnode = head;
        while(prevnode){
            if(temp && temp -> child){
                nextnode = temp -> next; //记录当前节点的下一个节点
                temp -> child -> prev = temp;
                temp -> next = flatten(temp -> child); //进入递归
                temp -> child = nullptr; //注销当前节点的child；
            }
            prevnode = temp; //记录null节点的前一个节点
            if(temp)    temp = temp -> next;
            if(nextnode && !temp){ //当同一级链表存在下一个节点（即，原来有child的节点的下一节点），且子链表到达null
                prevnode -> next = nextnode; //连接子节点和之前记录的nextnode所指链表 ---->这一步将其中两级双向链表扁平化
                nextnode -> prev = prevnode;
                temp = prevnode -> next;
                nextnode = nullptr; //记得清空使用过的nextnode，否则会将无限连接nextnode所指链表
            }
        }
        return head;
    }
};
```
### 思路二
stack
- 常规DFS遍历，使用stack（LIFO）遍历整个链表
- 取出每个节点，压入栈内，再按顺序（LIFO）一个个取出，加上两个节点间的关系
- 记得清空`child`指针
- 注意while循环内前两个`if`语句的顺序，先`next`的节点，后`child`节点。(LIFO)
### cpp代码
```
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)   return nullptr;
        Node *cur;
        stack <Node*> stk;
        stk.push(head);
        Node *pre = nullptr;
        while(!stk.empty()){
            cur = stk.top();
            stk.pop();
            if(cur -> next){
                stk.push(cur -> next);
            }
            if(cur -> child){
                stk.push(cur -> child);
                cur -> child = nullptr;
            }
            if(pre){
                pre -> next = cur;
                cur -> prev = pre;
            }
            pre = cur;
        }
        return head;
    }
};
```
