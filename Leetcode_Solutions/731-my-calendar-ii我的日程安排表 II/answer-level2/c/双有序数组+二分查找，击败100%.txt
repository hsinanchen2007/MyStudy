```

typedef struct {
    int start;
    int end;
}BOOKING;

#define MAX_BOOK_NUM (1000)
typedef struct MyCalendar_ {
    BOOKING book[MAX_BOOK_NUM];
    int bnum;
    BOOKING *sorted[MAX_BOOK_NUM];
    int num;
    int conflict[MAX_BOOK_NUM];
    int cnum;
    BOOKING cbook[MAX_BOOK_NUM];
    struct MyCalendar_ *next;
} MyCalendar;

#define MAX_OVERLAP_NUM (2)
typedef struct {
    MyCalendar calendar[MAX_OVERLAP_NUM];
} MyCalendarTwo;


MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo* obj = (MyCalendarTwo*)malloc(sizeof(MyCalendarTwo));
    memset(obj, 0, sizeof(MyCalendarTwo));
    
    int i;
    for (i = 0; i < MAX_OVERLAP_NUM - 1; i++) {
        obj->calendar[i].next = &obj->calendar[i+1];
    }
    obj->calendar[i].next = NULL;
    
    return obj;
}

void myCalendarInsert(MyCalendar *obj, int pos, int start, int end) {
    assert(pos <= obj->num);
    
    BOOKING *b = &obj->book[obj->bnum++];
    b->start = start;
    b->end = end;
    
    memmove(&obj->sorted[pos+1], &obj->sorted[pos], sizeof(BOOKING *)*(obj->num-pos));
    obj->sorted[pos] = b;
    obj->num++;
}

void myCalendarRemove(MyCalendar *obj, int pos, int num) {
    assert(pos >= 0);
    assert(pos + num <= obj->num);
    
    int size = obj->num - pos - num;
    memmove(&obj->sorted[pos], &obj->sorted[pos+num], sizeof(BOOKING *)*size);
    obj->num -= num;
}

bool myCalendarCheck(MyCalendar *obj, int start, int end) {
    if (!obj->num) {
        return true;
    }
    
    int left = 0;
    int right = obj->num - 1;
    if (end <= obj->sorted[left]->start) {
        return true;
    }
    
    if (start >= obj->sorted[right]->end) {
        return true;
    }
    
    while(left < right) {
        int mid = left + (right - left) / 2;
        if (start > obj->sorted[mid]->start) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    
    if (end > obj->sorted[left]->start) {
        return false;
    }
    
    if (left - 1 >= 0 && obj->sorted[left-1]->end > start) {
        return false;
    }
    
    return true;
}

void myCalendarBookInternal(MyCalendar *obj, int start, int end) {
    if (!obj->num) {
        myCalendarInsert(obj, 0, start, end);
        return;
    }
    
    int left = 0;
    int right = obj->num - 1;
    if (end <= obj->sorted[left]->start) {
        myCalendarInsert(obj, 0, start, end);
        return;
    }
    
    if (start >= obj->sorted[right]->end) {
        myCalendarInsert(obj, obj->num, start, end);
        return;
    }
    
    while(left < right) {
        int mid = left + (right - left) / 2;
        if (start > obj->sorted[mid]->start) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    
    myCalendarInsert(obj, left, start, end);
    return;
}

bool myCalendarBook(MyCalendar *obj, int start, int end) {
    if (!myCalendarCheck(obj->next, start, end)) {
        return false;
    }
    
    if (!obj->num) {
        myCalendarInsert(obj, obj->num, start, end);
        return true;
    }
    
    int left = 0;
    int right = obj->num - 1;
    if (end <= obj->sorted[left]->start) {
        myCalendarInsert(obj, 0, start, end);
        return true;
    }
    
    if (start >= obj->sorted[right]->end) {
        myCalendarInsert(obj, obj->num, start, end);
        return true;
    }
    
    if (start >= obj->sorted[right]->start) {
        left = obj->num;
    }
    else if (start <= obj->sorted[0]->start) {
        left = 0;
    }
    else {
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (start > obj->sorted[mid]->start) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
    }
    
    int ustart = start;
    int uend = end;
    
    obj->cnum = 0;
    int pos = left;
    if (left - 1 >= 0 && obj->sorted[left-1]->end > start) {
        BOOKING *b = obj->sorted[left-1];
        ustart = ustart < b->start ? ustart : b->start;
        uend = uend > b->end ? uend : b->end;
        
        int nstart = start;
        int nend = b->end < end ? b->end : end;
        
        pos--;
        obj->cbook[obj->cnum].start = nstart;
        obj->cbook[obj->cnum].end = nend;
        obj->conflict[obj->cnum++] = left - 1;
    }
    
    for (int i = left; i < obj->num; i++) {
        BOOKING *b = obj->sorted[i];
        if (end <= b->start) {
            break;
        }
        
        int nstart = b->start;
        int nend = b->end < end ? b->end : end;
        ustart = ustart < b->start ? ustart : b->start;
        uend = uend > b->end ? uend : b->end;
        
        obj->cbook[obj->cnum].start = nstart;
        obj->cbook[obj->cnum].end = nend;
        obj->conflict[obj->cnum++] = i;
    }
        
    for (int i = 0; i < obj->cnum; i++) {
        BOOKING *b = &obj->cbook[i];
        myCalendarBookInternal(obj->next, b->start, b->end);
    }
    
    myCalendarRemove(obj, pos, obj->cnum);
    myCalendarInsert(obj, pos, ustart, uend);
    return true;
}

bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
    MyCalendar *c = &obj->calendar[0];
    bool success = myCalendarBook(c, start, end);
    
    return success;
}

void myCalendarTwoFree(MyCalendarTwo* obj) {
    free(obj);
}

/**
 * Your MyCalendarTwo struct will be instantiated and called as such:
 * MyCalendarTwo* obj = myCalendarTwoCreate();
 * bool param_1 = myCalendarTwoBook(obj, start, end);
 
 * myCalendarTwoFree(obj);
*/
```
