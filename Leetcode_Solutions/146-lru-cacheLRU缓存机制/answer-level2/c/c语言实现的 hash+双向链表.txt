写个题解记录下这题，写了好久。。。。。。
算法核心思路：
    要用接近O（1）的时间复杂度选用：hash表+双向链表，
    缓存空间恒为capacity，hash冲突采用线性探索的开发地址法，hash码相同的数据用链表链接，提高查找效率

    put算法思路
    一、如果节点为空直接存入，结束
    二、节点不为空，如有相同的key，则替换,结束
    三、节点不为空、缓存已满
        1、最少使用节点和要添加元素hashcode相同,新元素替换最少使用节点，结束
        2、最少使用节点和要添加节点hashcode不同，删除最少使用节点，进入第四步
            a、最少使用节点len为0（表示index和存储数据的hashcode不同，不是该节点应存的数据）：找出该数据的链头，并删除链的该节点（注意拼接）
            b、最少使用节点len为1：直接删除
            c、最少使用节点len为2：用该节点的下一节点替换该元素、删除下一节点空间（注意拼接）（注意不直接删除）
    四、节点不为空、有空位
        a、该节点len等于0，把该节点移到其他空节点（注意拼接），新元素填充该节点
        b、该节点len大于0，找一个空位添加元素，该节点 链上新添加的节点

    贴一个打印的缓存结构好j理解
    capacity=10,size=10,head.key=11,tail.key=13{
        0,size:0==>key:12,val:17->;
        1,size:2==>key:1,val:20->key:11,val:7->;
        2,size:2==>key:2,val:15->key:12,val:17->;
        3,size:2==>key:3,val:16->key:13,val:17->;
        4,size:0==>key:13,val:17->;
        5,size:1==>key:5,val:18->;
        6,size:1==>key:6,val:19->;
        7,size:0==>key:11,val:7->;
        8,size:1==>key:8,val:1->;
        9,size:1==>key:9,val:1->;
        orderNext=>key:11,val:7->key:8,val:1->key:5,val:18->key:6,val:19->key:9,val:1->key:12,val:17->key:1,val:20->key:3,val:16->key:2,val:15->key:13,val:17->;
        orderLast=>key:13,val:17->key:2,val:15->key:3,val:16->key:1,val:20->key:12,val:17->key:9,val:1->key:6,val:19->key:5,val:18->key:8,val:1->key:11,val:7->;
    }

执行用时 :92 ms, 在所有 c 提交中击败了99.72%的用户
内存消耗 :25.9 MB, 在所有 c 提交中击败了75.00%的用户
```
#define key_type int
#define val_type int

#define DEBUG key==-1

struct LRUNode{
    int index;//该节点的hashcode（在数组中的位置）,不变
    bool isFull;//是否有数据
    key_type key;
    val_type val;
    int len;//hashcode和index相同的链表next的长度
    struct LRUNode* next;//发生哈希冲突时、链接到下一节点
    struct LRUNode* orderNext;//排序
    struct LRUNode* orderLast;
};

//设置一个节点
void LRUSetNode(struct LRUNode* node,bool isFull,key_type key,val_type val,int len){
    node->isFull=isFull;
    node->key=key;
    node->val=val;
    node->len=len;
}

typedef struct{
    struct LRUNode** dates;
    int capacity;
    int size;
    struct LRUNode* head;
    struct LRUNode* tail;
} LRUCache;

//打印节点明细
void LRUNodePrint(struct LRUNode* node,int maxLen){
    if(node->isFull==false)printf("empty");
    else{
        while(node!=NULL&&maxLen>0){
            printf("key:%i,val:%i->",node->key,node->val);
            maxLen--;
            node=node->next;
        }
    }
    printf(";\r\n");
}

//打印缓存详细
void lRUCachePrint(LRUCache* obj){
    //打印表概况
    printf("capacity=%i,size=%i,head.key=%i,tail.key=%i{\r\n"
    ,obj->capacity,obj->size,obj->head==NULL?-1:obj->head->key,obj->tail==NULL?-1:obj->tail->key);
    //打印各个节点
    for(int i=0;i<obj->capacity;i++){
        printf("%i,size:%i==>",(obj->dates)[i]->index,(obj->dates)[i]->len);
        LRUNodePrint((obj->dates)[i],obj->capacity);
    }
    //打印正向排序
    struct LRUNode* node=obj->head;
    printf("orderNext=>");
    while(node!=NULL){
        printf("key:%i,val:%i->",node->key,node->val);
        node=node->orderNext;
    }
    printf(";\r\n");
    //打印逆序排序
    node=obj->tail;
    printf("orderLast=>");
    while(node!=NULL){
        printf("key:%i,val:%i->",node->key,node->val);
        node=node->orderLast;
    }
    printf(";\r\n");
    //结束
    printf("}\r\n");
}

//hash算法，整型直接取余
int lRUHashCode(int key,int capacity){
    if(key==INT_MIN)key=0;
    else if(key<0)key=-key;
    return key % capacity;//整数哈希key，直接取余
}

//创建缓存空间
LRUCache* lRUCacheCreate(int capacity) {
    //printf("Create start!\r\n");
    LRUCache* result=(LRUCache*)malloc(sizeof(LRUCache));
    memset(result, 0, sizeof(LRUCache));
    struct LRUNode** dates=(struct LRUNode**)malloc(sizeof(struct LRUNode*)*capacity);
    for(int i=0;i<capacity;i++){
        dates[i]=(struct LRUNode*)malloc(sizeof(struct LRUNode));
        memset(dates[i], 0, sizeof(struct LRUNode));
        dates[i]->index=i;
    }
    result->dates=dates;
    result->capacity=capacity;
    //lRUCachePrint(result);
    return result;
}

//排序:type=0提升，type=1增加，type=2删除，type=3移动
void lUROrder(LRUCache* obj,struct LRUNode* node,struct LRUNode* moveNode,int type){
    switch(type){
        case 0:
            //提升
            if(obj->head==node)return;
            struct LRUNode* temp=node->orderLast;
            if(node==obj->tail)obj->tail=temp;
            temp->orderNext=node->orderNext;
            if(node->orderNext!=NULL)node->orderNext->orderLast=temp;
            node->orderNext=obj->head;
            node->orderLast=NULL;
            obj->head->orderLast=node;
            obj->head=node;
            break;
        case 1:
            //增加
            if(obj->head==NULL){
                obj->head=node;
                obj->tail=node;
            }else{
                obj->head->orderLast=node;
                node->orderNext=obj->head;
                node->orderLast=NULL;
                obj->head=node;
            }
            break;
        case 2:
            //删除
            if(node==obj->head){
                obj->head=obj->head->orderNext;
                if(obj->head==NULL)obj->tail=NULL;
                else obj->head->orderLast=NULL;
            }
            else if(node==obj->tail){
                obj->tail=node->orderLast;
                obj->tail->orderNext=NULL;
            }
            else {
                struct LRUNode* temp=node->orderLast;
                temp->orderNext=node->orderNext;
                if(node->orderNext!=NULL)node->orderNext->orderLast=temp;
            }
            node->orderLast==NULL;
            node->orderNext=NULL;
            break;
        case 3:
            //移动
            if(moveNode==obj->head)obj->head=node;
            if(moveNode==obj->tail)obj->tail=node;
            node->orderNext=moveNode->orderNext;
            node->orderLast=moveNode->orderLast;
            if(moveNode->orderLast!=NULL)moveNode->orderLast->orderNext=node;
            if(moveNode->orderNext!=NULL)moveNode->orderNext->orderLast=node;
            moveNode->orderNext=NULL;
            moveNode->orderLast=NULL;
            break;
    }
}

//get 实现相对简单
int lRUCacheGet(LRUCache* obj, int key) {
    //printf("Get start! key=%i\r\n",key);
    int hashCode=lRUHashCode(key,obj->capacity);
    struct LRUNode* node = (obj->dates)[hashCode];
    if(node->isFull||node->len>0){
        while(node!=NULL){
            if(node->key==key){
                lUROrder(obj,node,NULL,0);
                return node->val;
            }
            node=node->next;
        }
    }
    return -1;
}

//删除指定节点，链表长度要大于等于2，删除成功返回true
bool lRUDelNode(struct LRUNode* head,struct LRUNode* del){
    if(head==NULL){
        printf("lRUDelNode Err:head is null!");
        return false;
    }
    if(head==del){
        printf("lRUDelNode Err:head and del same!");
        return false;
    }
    head->len=(head->len)-1;//记得长度减一
    while(head->next!=del){
        if(head->next==NULL){
            printf("lRUDelNode Err:not search del node!");
            return false;
        }
        head=head->next;
    }
    head->next=del->next;
    LRUSetNode(del,false,0,0,0);//置空删除的元素
    del->next=NULL;
    return true;
}

//若存在相同的key则更新数据返回更新数据；否则返回NULL
struct LRUNode* lRUUpdateNode(struct LRUNode* head,int key, int val){
    while(head!=NULL){
        if(head->key==key){
            LRUSetNode(head,true,key,val,head->len);
            return head;
        }
        head=head->next;
    }
    return NULL;
}

//以某个节点为基准寻找空位
struct LRUNode* lRUFindEmpty(LRUCache* obj,struct LRUNode* node){
    int index=node->index;
    while((obj->dates)[index]->isFull){
        index = lRUHashCode(++index,obj->capacity);
        if(index==node->index){
            printf("lRUFindEmpty Err:no empty!");
            return NULL;
        }
    }
    return (obj->dates)[index];
}

//移动指定节点到其他空节点，链表长度要大于等于2，成功返回true
bool lRUMoveNode(LRUCache* obj,struct LRUNode* moveNode,struct LRUNode* emptyNode){
    int hashCode=lRUHashCode(moveNode->key,obj->capacity);
    struct LRUNode* head=(obj->dates)[hashCode];
    if(head==moveNode){
        printf("lRUMoveNode Err:head and moveNode same!\r\n");
        lRUCachePrint(obj);
        return false;
    }
    while(head->next!=moveNode){
        if(head->next==NULL){
            printf("lRUMoveNode Err:not search moveNode!");
            lRUCachePrint(obj);
            return false;
        }
        head=head->next;
    }
    if(emptyNode==NULL){
        emptyNode=lRUFindEmpty(obj,moveNode);
    }
    LRUSetNode(emptyNode,true,moveNode->key,moveNode->val,moveNode->len);
    head->next=emptyNode;
    emptyNode->next=moveNode->next;
    LRUSetNode(moveNode,false,0,0,0);
    moveNode->next=NULL;
    //排序
    lUROrder(obj,emptyNode,moveNode,3);
    return true;
}

void lRUCachePut(LRUCache* obj, int key, int val) {
    //printf("Put start! key=%i,val=%i\r\n",key,val);
    int hashCode=lRUHashCode(key,obj->capacity);
    struct LRUNode* saveNode = (obj->dates)[hashCode];
    //一、如果节点为空直接存入，结束
    if(!saveNode->isFull){
        if(DEBUG)printf("lRUCachePut debug：!saveNode->isFull\r\n");
        LRUSetNode(saveNode,true,key,val,(saveNode->len)+1);
        obj->size=(obj->size)+1;
        //排序
        lUROrder(obj,saveNode,NULL,1);
        if(DEBUG)lRUCachePrint(obj);
        return;
    }
    //二、节点不为空，如有相同的key，则替换,结束
    if(lRUHashCode(saveNode->key,obj->capacity)==hashCode){//也可(saveNode->len)>0
        struct LRUNode* replace=lRUUpdateNode(saveNode,key,val);
        if(replace!=NULL){
            if(DEBUG)printf("lRUCachePut debug：有同样的key，替换\r\n");
            //排序
            lUROrder(obj,replace,NULL,0);
            if(DEBUG)lRUCachePrint(obj);
            return;
        }
    }
    struct LRUNode* delNode=NULL;
    //三、节点不为空、缓存已满
    if(obj->capacity==obj->size){
        int tailHashCode=lRUHashCode((obj->tail)->key,obj->capacity);
        //1、最少使用节点和要添加元素hashcode相同,新元素替换最少使用节点，结束
        if(tailHashCode==hashCode){//此时tailHashCode=hashCode=saveHashCode
            if(DEBUG)printf("lRUCachePut debug：tailHashCode==hashCode\r\n");
            LRUSetNode(obj->tail,true,key,val,obj->tail->len);
            //排序
            lUROrder(obj,obj->tail,NULL,0);
            if(DEBUG)lRUCachePrint(obj);
            return;
        }
        //2、最少使用节点和要添加节点hashcode不同，删除最少使用节点，进入第四步
        //a、最少使用节点len为0：找出改节点的链头，并删除链的该节点（注意拼接）
        if(obj->tail->len==0){
            if(DEBUG)printf("lRUCachePut debug：tail len==0\r\n");
            lRUDelNode((obj->dates)[tailHashCode],obj->tail);
            delNode=obj->tail;
            //排序
            lUROrder(obj,delNode,NULL,2);
        }
        //b、最少使用节点len为1：直接删除
        else if(obj->tail->len==1){
            if(DEBUG)printf("lRUCachePut debug：tail len==1\r\n");
            LRUSetNode(obj->tail,false,0,0,0);
            delNode=obj->tail;
            //排序
            lUROrder(obj,delNode,NULL,2);
        }
        //c、最少使用节点len为2：用该节点的下一节点替换该元素、删除下一节点空间（注意拼接）
        else if(obj->tail->len>1){
            if(DEBUG)printf("lRUCachePut debug：debug：tail len>1\r\n");
            struct LRUSetNode* oldTail=obj->tail;
            delNode=obj->tail->next;
            LRUSetNode(obj->tail,true,delNode->key,delNode->val,obj->tail->len);
            lRUDelNode(obj->tail,delNode);
            //排序
            lUROrder(obj,obj->tail,NULL,2);
            lUROrder(obj,oldTail,delNode,3);
        }else printf("lRUCachePut Err:A node len<0 !\r\n");
        obj->size=(obj->size)-1;//情况2 c删除一个节点 长度减一
    }
    //四、节点不为空、有空位
    //a、该节点len等于0，把该节点移到其他空节点（注意拼接），新元素填充该节点
    if(saveNode->len==0){
        if(DEBUG)printf("lRUCachePut debug：有空位、saveNode->len==0\r\n");
        if(saveNode!=delNode)lRUMoveNode(obj,saveNode,delNode);
        LRUSetNode(saveNode,true,key,val,1);
        //排序
        lUROrder(obj,saveNode,NULL,1);
    }
    //b、该节点len大于0，找一个空位添加元素，该节点 链上新添加的节点
    else if(saveNode->len>0){
        if(DEBUG)printf("lRUCachePut debug：有空位、saveNode->len>0\r\n");
        if(delNode==NULL){
            delNode=lRUFindEmpty(obj,saveNode);
        }
        saveNode->len=(saveNode->len)+1;
        while(saveNode->next!=NULL){
            saveNode=saveNode->next;
        }
        saveNode->next=delNode;
        LRUSetNode(delNode,true,key,val,0);
        //排序
        lUROrder(obj,delNode,NULL,1);
    }else printf("lRUCachePut Err:A node len<0 !\r\n");
    obj->size=(obj->size)+1;//情况四长度加一
    if(DEBUG)lRUCachePrint(obj);
}

void lRUCacheFree(LRUCache* obj) {}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
```
