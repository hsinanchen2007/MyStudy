```
typedef struct BOOKING_ {
    int start;
    int end;
}BOOKING;

#define CALENDAR_SIZE (1000)

typedef struct {
    BOOKING book[CALENDAR_SIZE];
    BOOKING *sorted[CALENDAR_SIZE];
    int num;
} MyCalendar;


MyCalendar* myCalendarCreate() {
    MyCalendar *c = malloc(sizeof(MyCalendar));
    memset(c, 0, sizeof(MyCalendar));
    return c;
}

void myCalendarInsert(MyCalendar* obj, int pos, int start, int end) {
    assert(obj->num < CALENDAR_SIZE);
    assert(pos <= obj->num);
    BOOKING *b = &obj->book[obj->num];
    b->start = start;
    b->end = end;
    
    memmove(&obj->sorted[pos+1], &obj->sorted[pos], sizeof(BOOKING*)*(obj->num-pos));
    obj->sorted[pos] = b;
    obj->num++;
}

void myCalendarPushback(MyCalendar* obj, int start, int end)
{
    myCalendarInsert(obj, obj->num, start, end);
}

void myCalendarPushfront(MyCalendar* obj, int start, int end)
{
    myCalendarInsert(obj, 0, start, end);
}

bool myCalendarBook(MyCalendar* obj, int start, int end) {
    if (start >= end) {
        return false;
    }
    
    if (!obj->num) {
        myCalendarPushback(obj, start, end);
        return true;
    }
    
    int left = 0;
    if (end <= obj->sorted[left]->start) {
        myCalendarPushfront(obj, start, end);
        return true;
    }
    
    int right = obj->num - 1;
    if (start >= obj->sorted[right]->end) {
        myCalendarPushback(obj, start, end);
        return true;
    }
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        BOOKING *b = obj->sorted[mid];
        if (b->start < start) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    
    BOOKING *ins = obj->sorted[left];
    if (end > ins->start) {
        return false;
    }
    
    if (left - 1 >= 0) {
        BOOKING *prev = obj->sorted[left-1];
        if (prev->end > start) {
            return false;
        }
    }
    
    myCalendarInsert(obj, left, start, end);
    return true;
}

void myCalendarFree(MyCalendar* obj) {
    free(obj);   
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);
 
 * myCalendarFree(obj);
*/
```

