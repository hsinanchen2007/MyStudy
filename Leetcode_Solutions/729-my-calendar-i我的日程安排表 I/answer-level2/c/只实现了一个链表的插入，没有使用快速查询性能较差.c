# 只实现了一个链表的插入，没有使用快速查询性能较差
执行用时 :
192 ms
, 在所有 C 提交中击败了
15.79%
的用户
内存消耗 :
21.6 MB
, 在所有 C 提交中击败了
100.00%
的用户

typedef struct Calendar{
    int start;
    int end;
    struct Calendar *next;
} MyCalendar;


MyCalendar* myCalendarCreate() {
    MyCalendar *obj = (MyCalendar *)malloc(sizeof(MyCalendar));
    memset(obj, 0, sizeof(MyCalendar));
    return obj;
}

bool myCalendarBook(MyCalendar* obj, int start, int end) {
    MyCalendar *temp = obj;
    while(temp->next != NULL) {
        if (end <= temp->next->start) {
            MyCalendar *node = myCalendarCreate();
            node->start = start;
            node->end = end;
            node->next = temp->next;
            temp->next = node;
            return true;
        }else if (start >= temp->next->end) {
            temp = temp->next;
        }else{
            return false;
        }
    }
    if (temp->next == NULL) {
        MyCalendar *node = myCalendarCreate();
        node->start = start;
        node->end = end;
        temp->next = node;
    }
    return true;
}

void myCalendarFree(MyCalendar* obj) {
    MyCalendar *temp = NULL;
    while(obj->next != NULL) {
        temp = obj;
        obj = obj->next;
        free(temp);
    }
    free(obj);
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);
 
 * myCalendarFree(obj);
*/
```
