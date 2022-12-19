### 执行结果
执行用时 :
40 ms
, 在所有 cpp 提交中击败了
98.98%
的用户
内存消耗 :
19.1 MB
, 在所有 cpp 提交中击败了
87.68%
的用户

### 代码

```cpp
//ListNode力扣已经定义
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
typedef struct Node{
    
    int val;
    Node *next;
    Node(int a) : val(a),next(NULL){}
    
};

class MyLinkedList {
private:
    Node *head=nullptr;//头结点
    Node *tail=nullptr;//尾节点
    int time=0;
    int size=0;
    
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        
        //先验证数据有有效性
        //        分三种情况：取头，中间、尾节点
        //
        if(index>=0 && index<size){
            if(index==0){
                return head->val;
            }else if (index==size-1){
                return tail->val;
            }else{
                //遍历的目的是为了得到index的node
                int j=1;
                Node *node=head;
                for(;j<index+1;j++){
                    node=node->next;
                }
                if(!node ||j>index+2) return -1;
                int result=node->val;
                return result;
                
            }
        }
        return -1;
        
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *node= new Node(val);
        node->next=head;
        head=node;
        size++;
        if (size==1) {
            tail=head;
        }
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *node= new Node(val);
        if(!tail && !head){
            head=node;
        }else if(!head && tail){
            cout<<"bug，head为不存在，tail存在"<<endl;
        }else if(head && !tail){
            cout<<"bug，head为存在，tail不存在"<<endl;
        }else{
            tail->next=node;
        }
        tail=node;
        size++;
    }
    
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        //思路：
        //首先检验index是否有效
        //只有三种插入情况，插入表头、表中、表尾
        //new一个val值的节点
        //再插入
        if(index>=0 && index<=size){
            Node *insNode=new Node(val);
            if(index==0){//插入表头是什么条件
                insNode->next=head;
                head=insNode;
                if(size==0){
                    tail=insNode;
                }
                size++;
            }else if(index==size){//插入表尾是什么条件
                addAtTail(val);
            }else{//插入表中是什么条件
                Node *node=head;
                //遍历的目的是得到index前一个node
                for(int j=1;j<index;j++){
                    node=node->next;
                }
                insNode->next=node->next;
                node->next=insNode;
                size++;
            }
            
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    
    void deleteAtIndex(int index) {
        //        先验证index有效性
        //三种情况，删头结点不需要遍历，直接改变head的值;删中间节点需要i遍历，不需要改变链表head或者tail的值；
        //        删尾节点，需要先遍历再改变尾节点的值
        
        if(index>=0 && index<size){
            Node *node=head;
            if(index==0){
                head=head->next;
            }else{
                int j=1;
                //遍历的目的是为了得到目标index上一个Node
                while (node && j<index) {
                    node=node->next;
                    j++;
                }
                if(index==size-1){
                    node->next=nullptr;
                    tail=node;
                }else{
                    node->next=node->next->next;
                }
            }
            size--;
        }
    }
    
    
};
```