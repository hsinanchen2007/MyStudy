```
//执行用时 :64 ms, 在所有 C++ 提交中击败了83.38%的用户
class MyLinkedList {
public:
    typedef struct node { //这里首先定义结点的数据结构
        int val;
        struct node* next;
        node(int _val) { //构造方法
            val = _val;
            next = NULL;
        }
    }*List,*NODE;
    int maxsize; //链表的当前长度
    List list; //创建链表
    NODE lastnode;//链表尾结点
    MyLinkedList() { //初始化
        maxsize = 0;
        lastnode = NULL;
        list = new node(0);
    }
    int get(int index) {
        if(index<0||index>maxsize-1) return -1; //越界返回
        NODE p = list->next;
        for(int i=0;i<index;i++) p=p->next;
        return p->val;
    }
    
    void addAtHead(int val) {
        NODE p = new node(val);
        if(!lastnode) { //根据链表是否为空分情况讨论
            list->next = p;
            lastnode = p;
        }else {
            p->next = list->next;
            list->next = p;
        }
        maxsize++;
    }
    void addAtTail(int val) {
        NODE p = new node(val);
        if(!lastnode) { //根据链表是否为空分情况讨论
            list->next = p;
            lastnode = p;
        }else {
            lastnode->next = p;
            lastnode = p;
        }
        maxsize++;
    }
    void addAtIndex(int index, int val) {
        if(index>maxsize) return; //index超过最大长度直接返回
        else if(index==maxsize) addAtTail(val); //index等于最大长度时采用尾插法
        else if(index<=0) addAtHead(val); //index（小于，这个是个坑点）等于0时采用头插法
        else { //其余情况就是在两个结点中插入一个结点
            NODE head = list->next;
            NODE p = new node(val);
            for(int i=0;i<index-1;i++) head=head->next; //找到待插位置的前一个元素
            p->next = head->next;
            head->next = p;
            maxsize++;
        }
    }
    void deleteAtIndex(int index) {
        if(index<0||index>maxsize-1) return; //index越界直接返回
        if(index==0) list->next = list->next->next; //删除第一个元素直接改头结点的next即可
        else {
            NODE p = list->next;
            for(int i=0;i<index-1;i++) p=p->next; //找到待删位置的前一个元素
            if(index==maxsize-1) lastnode = p; //注意如果删除最后一个元素必须要更新lastnode
            p->next = p->next->next;
        }
        maxsize--;
        if(!maxsize) lastnode = NULL; //如果链表长度为0，lastnode值置为空
    }
};
```
