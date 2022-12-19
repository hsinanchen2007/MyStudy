步骤：
    1. flag[i][j]保存“从0开始到(i,j)位置的最小值中的最大值。STACK s保存未走过的所有路径，s.top保存最大值。
    2. 初始flag[100][100]全部设置为0， flag[0][0] = A[0][0]。push(s, -1);
    3. 如果堆栈为空，就跳出来。
    4. 进入新的节点x, y后，找出“上下左右”最大方位A[nx][ny]，判断MIN(flag[x,y],A[nx][ny])是否大于pop(s);
    5. 如果大于，就将未选择的路径push(s,otherx,othery)，并跳转到nx,ny执行3。
    6. 如果小于，就pop(s)赋值给nx,ny，并跳转到3执行。

思路：从0,0开始，有两个方向dir1/dir2, 选择一个最大的方向dir1，沿着这个方向继续行走，并记录这个方向可能的其他secondMax方向，
	  如果遇到比secondMax还小的值，就跳到secondMax重复，直到记录值为空，或者找到了终点。
	  
待改进：在下面代码中，把PushStack函数中的查找动作加速一下，会更快一些。
![image.png](https://pic.leetcode-cn.com/1368b429d4b32e02c9bbe30d4a6a69a166bd5589277052022dd76d919f75eef3-image.png)

```
#define MIN(x, y) ((x) > (y)? (y): (x))

typedef struct {
    int r;
    int c;
    int val;
}ELEMENT;

typedef struct STACK_NODE{
    ELEMENT node;
    struct STACK_NODE *next;
    struct STACK_NODE *prev;
}HEAD;

HEAD *CreateLink(void)
{
    HEAD *p = (HEAD*)malloc(sizeof(HEAD));
    if (p == NULL) {
        return p;
    }
    p->next = p;
    p->prev = p;

    memset(&(p->node), 0xFF, sizeof(ELEMENT));
    return p;
}

static inline bool IsEmpty(HEAD *p)
{
    return p->next == p;
}

void PushStack(HEAD *p, ELEMENT *e)
{
    HEAD *n = (HEAD*)malloc(sizeof(HEAD));
    if (n == NULL) {
        return n;
    }
    memcpy(&(n->node), e, sizeof(ELEMENT));

    HEAD *t = p->next;
    HEAD *s = p->prev;
    while (t != p && t->node.val < e->val) {
        t = t->next;
		if (s != p && s->node.val <= e->val) {
			t = s->next;
			break;
		}		
		s = s->prev;
    }
    t = t->prev;
    n->next = t->next;
    t->next->prev = n;
    t->next = n;
    n->prev = t;
}

static inline void PeekStack(HEAD *p, ELEMENT *out)
{
    if (IsEmpty(p)) {
        memset(out, 0xFF, sizeof(ELEMENT));
    } else {
        memcpy(out, &(p->prev->node), sizeof(ELEMENT));
    }
}

static inline void PopStack(HEAD *p, ELEMENT *out)
{
    if (IsEmpty(p)) {
        return;
    }
    
    HEAD *n = p->prev;
    memcpy(out, &(n->node), sizeof(ELEMENT)); 
    n->prev->next = n->next;
    n->next->prev = n->prev;
    free(n);
}

bool PreHandle(int **A, int rowSize, int colSize, int flag[][100], int stackMark[][100], HEAD* p)
{
    bool ret = false;
    if (IsEmpty(p) == true) {
        return ret;
    }

    ELEMENT ele;
    PopStack(p, &ele);

    int nowx = ele.r;
    int nowy = ele.c;
    if (nowx == rowSize - 1 && nowy == colSize - 1) {
        return true;
    }

    PeekStack(p, &ele);

    int recordMax = (ele.val > 0 ? ele.val : INT_MIN);
    
    ELEMENT tmp[4] = {{-1,0, -1}, {1,0, -1}, {0, 1, -1}, {0, -1, -1}};
    for (int j = 0; j < sizeof(tmp)/sizeof(ELEMENT); j++) {
        int x = nowx + tmp[j].r;
        int y = nowy + tmp[j].c;
        if (x >= 0 && x < rowSize && y >= 0 && y < colSize && flag[x][y] == 0 && stackMark[x][y] == 0) {
            ELEMENT tmp = {.r = x, .c = y, .val = A[x][y]};
            PushStack(p, &tmp);
            stackMark[x][y] = 1;
        }
    }
    
    PeekStack(p, &ele);
    
    if (ele.val < recordMax) {
        flag[ele.r][ele.c] = ele.val;
        PopStack(p, &ele);
    } else {
        flag[ele.r][ele.c] = MIN(flag[nowx][nowy], A[ele.r][ele.c]);
    }

    ret = PreHandle(A, rowSize, colSize, flag, stackMark, p);
    return ret;
}

int maximumMinimumPath(int** A, int ASize, int* AColSize){
    if (ASize == 0 || A == NULL || AColSize == NULL) {
        return 0;
    }
    int flag[100][100] = {0};
    int stackMark[100][100] = {0};

    flag[0][0] = A[0][0];
    stackMark[0][0] = 1;
    
    HEAD *p = CreateLink();

    ELEMENT z = {.r = 0, .c = 0, .val = A[0][0]};
    PushStack(p, &z);

    PreHandle(A, ASize, *AColSize, flag, stackMark, p);
    return flag[ASize - 1][*AColSize - 1];
}
```
