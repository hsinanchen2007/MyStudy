Python 时间93%，空间98%
```
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.val = []
        self.min_num = []
        

    def push(self, x: int) -> None:
        self.val.append(x)
        if self.min_num == []:
            self.min_num.append(x)
        else:
            if x < self.min_num[-1]:
                self.min_num.append(x)
            else:
                self.min_num.append(self.min_num[-1])
        

    def pop(self) -> None:
        self.val.pop()
        self.min_num.pop()


    def top(self) -> int:
        return self.val[-1]
        

    def getMin(self) -> int:
        return self.min_num[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```


C 时间66%，空间95%
由于不确定总大小，所以使用链表而不是列表。一开始想到了反向链表，但是反向链表头指针会动，必须传二级指针进去；但题目只能传一级指针。
后来才想到声明一个栈结构，专门存头指针。
```
struct minStackNode{
    struct minStackNode* last;
    int val;
    int min_num;    
};

typedef struct minStack{
    struct minStackNode* current_node;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->current_node = NULL;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    struct minStackNode* node = (struct minStackNode*)malloc(sizeof(struct minStackNode));
    node->val = x;
    if (!(obj->current_node)){
        node->last = NULL;
        node->min_num = x;
    }
    else{
        node->last = obj->current_node;
        node->min_num = x < obj->current_node->min_num ? x : obj->current_node->min_num;
    }
    obj->current_node = node;
}

void minStackPop(MinStack* obj) {
    struct minStackNode* temp_node = obj->current_node;
    obj->current_node = temp_node->last;
    free(temp_node);
}

int minStackTop(MinStack* obj) {
    return obj->current_node->val;
}

int minStackGetMin(MinStack* obj) {
    return obj->current_node->min_num;
}

void minStackFree(MinStack* obj) {
    struct minStackNode* temp;
    while (obj->current_node){
        temp = obj->current_node->last;
        free(obj->current_node);
        obj->current_node = temp;
    }
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
```
