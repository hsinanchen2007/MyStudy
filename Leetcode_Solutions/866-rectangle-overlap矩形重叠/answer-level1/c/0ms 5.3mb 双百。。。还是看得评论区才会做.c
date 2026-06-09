### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct Point{
    int x;
    int y;
}Point;
bool up(Point a,int*p){
    if(a.y>=p[3]){
        return true;
    }
    return false;
}
bool down(Point a,int *p){
    if(a.y<=p[1]){
        return true;
    }
    return false;
}
bool left(Point a,int *p){
    if(a.x<=p[0]){
        return true;
    }
    return false;
}

bool right(Point a,int*p){
    if(a.x>=p[2]){
        return true;
    }
    return false;
}
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    Point a,b,c,d;
    a.x=rec1[0];
    a.y=rec1[1];
    b.x=rec1[2];
    b.y=rec1[1];
    c.x=rec1[2];
    c.y=rec1[3];
    d.x=rec1[0];
    d.y=rec1[3];
    if((up(a,rec2)&&up(b,rec2)&&up(c,rec2)&&up(d,rec2))
    ||(down(a,rec2)&&down(b,rec2)&&down(c,rec2)&&down(d,rec2))
    ||(left(a,rec2)&&left(b,rec2)&&left(c,rec2)&&left(d,rec2))
    ||(right(a,rec2)&&right(b,rec2)&&right(c,rec2)&&right(d,rec2))){
        return false;
    }
    return true;
}
```