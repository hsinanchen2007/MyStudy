简单思路，每次快照整个数组空间，然后使用快照ID 当做Key，C语言不支持MAP,所以占用一次申请50000（题目最大范围）KEY 空间
KEY         数据指针
SnapId 1 -> 数组1头指针
SnapId 2 -> 数组2头指针（如果不存在则赋值为NULL）
SnapId n -> 数组n头指针
这样Set 和 Get 时间复杂度全为O(1) 
复杂度方面 内存最大占用 50000*sizeof(int*) + 50000（数组长度）* sizeof(int) * 50000(SnapId个数) 约为 1000000KB=1G，虽然题目没有说明，但感觉肯定会超限。

如何只存储变化部分：
思路：
1. 在结构体存储快照次数 sid
2. 把每个数组元素变为结构体，存储数以及快照ID，多次快照后，形成链表
3. SET 方法处理：每次搜索链表，找到最大的快照ID： maxSid. 如果maxSid 与 数组的快照次数 sid 不相等，则申请新的节点，存储数据以及快照次数，并挂在链表尾部。
4. GET 方法处理：使用索引值，找到链表头指针，以次比较 maxSid 是否与 入参一致，如果找到就返回相应值，如果找不到则返回链表的尾（因为尾节点的快照ID 最大）。
关键问题：
1. Set 方法中如何找判断链表尾节点的 快照ID 是否与当前快照次数一致
2. Get 方法中如果快速找到 相应快照ID的节点

解决方法：
链表存储为双向链表，并开辟头指针（这个用来简化条件判断），这样SET方法的时间复杂度和空间复杂度都是O(1)；Get方法循环比较就可以完成，时间复杂度为O(n)，也可以接受。
```c []
typedef struct ItemTag{
    struct ItemTag *next;
    struct ItemTag *prev;
    int sid;
    int val;
}Item;
typedef struct {
    int length;
    int maxSid;  //快照次数
    Item data[]; //用来存储头指针
} SnapshotArray;

SnapshotArray* snapshotArrayCreate(int length) {
    SnapshotArray* ret=(SnapshotArray*)malloc(sizeof(SnapshotArray)+sizeof(Item)*length);
    memset(ret,0x0,sizeof(SnapshotArray)+sizeof(Item)*length);
    ret->maxSid=0;
    ret->length= length;
    return ret;
}
// 比较尾节点的快照ID 是否与快照次一致，一致直接修改相应值，不一致侧在尾部添加新节点，以保持链表有序。
void snapshotArraySet(SnapshotArray* obj, int index, int val) {
    Item *head=&obj->data[index];
    if(head->prev == NULL){   //初始化头节点
        Item *item=(Item*)malloc(sizeof(Item));
        item->val=0;
        item->sid=0;
        item->prev=head;
        item->next=head;
        head->prev=item;
        head->next=item;
    }
    if(head->prev->sid != obj->maxSid){ //只用判断尾节点的 快照ID是否与快照次数相等即可
        Item *tail = head->prev;
        Item *item=(Item*)malloc(sizeof(Item));
        item->sid=obj->maxSid;
        item->val=val;
        item->next=head;
        item->prev = tail;
        
        tail->next=item;
        head->prev=item;
        
    }else{
        head->prev->val=val;
    }
}

int snapshotArraySnap(SnapshotArray* obj) {
    return obj->maxSid++;
}
//每次都从头开始遍历，因为快照ID是有顺序的，找到相等的或者比指定ID大的即可结束。时间复杂度为O(n).
int snapshotArrayGet(SnapshotArray* obj, int index, int snap_id) {
    Item *head=&obj->data[index];
    while(head->next!=&obj->data[index] && head->next!=NULL){
        Item *t=head->next;
        if(t->sid == snap_id){
            return t->val;
        }else if(t->sid > snap_id){  //如果下个节点的快照ID比指定的ID大，则返回前节点的值。
            return head->val;
        }
        head=head->next;
    }
    return head->val;
}

void snapshotArrayFree(SnapshotArray* obj) {
    for(int i=0;i<obj->length;i++){
        Item *item=obj->data[i].next;
        while(item!= &obj->data[i] && item!=NULL){
            Item *next=item->next;
            free(item);
            item=next;
        }
    }
    free(obj);
}
```