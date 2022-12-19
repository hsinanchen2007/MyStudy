1、典型的线段树。
2、难点在于如何使用C语言实现。如果按照X轴逐点排布数据，有用例会报内存超大（比如用例中出现方块(10000000,100)）。解决方法：每个方块只抽取left和right值作为数组元素。并且对于重复元素要进行删除，比如方块A的left值等于方块B的right，那么只保留一个元素。也就是原始的A数组只保存不重复的方块顶点的X轴坐标。


typedef struct SegNode{
    int val;
}SegTree;
SegTree* tree;
int treeSize;

int top;
// debug printf
void PritfTree()
{
    return;
    printf("Tree--------\n");
    for (int i = 0; i < treeSize; i++) {
        printf("%d ",tree[i].val);
    }
    printf("\n");
}
void UpdateArry(int *arry, int cur, int top)
{
    for(int i = cur; i < top; i++) {
        arry[cur + 1] = arry[cur];
    }
}
void InsertArry(int *arry, int Len, int val)
{
    int i;
    for(i = 0; i < top; i++) {
        if (arry[i] == val) {
            return;
        }
    }
    arry[top] = val;
    int tmp;
    for(i = top; i > 0; i--) {
        if (arry[i] < arry[i - 1]) { // swap
            tmp = arry[i]; 
            arry[i] = arry[i - 1];
            arry[i - 1] = tmp;
        } else {
            break;
        }
    }
    top++;
}
// modify 二分查找
int FindArryIndex(int *arry, int val)
{
    for (int i = 0; i < top; i++) {
        if (arry[i] == val) {
            return i;
        }
    }
    return -1;
}

void BuildTree(int n)
{
    treeSize = (n<<2);
    tree = (SegTree*) malloc(treeSize*sizeof(SegTree));
    for (int i = 0; i < treeSize; i++) {
        tree[i].val = 0;
    }
}

int DoQuery(int ql, int qr, int root, int nl, int nr)
{
    //printf("DoQuery input: ql, qr, root, nl, nr\n");
    //printf("               %d, %d,  %d,  %d, %d\n", ql, qr, root, nl, nr);
    if (ql <= nl && qr >= nr) {
        return tree[root].val;
    }
    int mid = (nl + nr)>>1;

    int ansl = -1;
    int ansr = -1;
    if (ql <= mid) {
        ansl = DoQuery(ql, qr, root<<1, nl, mid);
    }
    if (qr > mid) {
        ansr = DoQuery(ql, qr, root<<1|1, mid + 1, nr);
    }
    return ansl > ansr ? ansl : ansr;
}
int Query(int ql, int qr)
{
    return DoQuery(ql, qr, 1, 0, top - 1);
}
void PushUp(int root)
{
    tree[root].val = tree[root<<1].val > tree[root<<1|1].val ? tree[root<<1].val : tree[root<<1|1].val;
}
void DoUpdate(int cur, int val, int root, int nl, int nr)
{
    if (nl == nr) {        
        //printf("DoUpdate: cur, val, root, nl, nr\n");
        //printf("DoUpdate: %d,   %d,  %d,  %d,  %d. old val = %d\n", cur, val, root, nl, nr, tree[root].val);
        tree[root].val = val;        
        return;
    }
    int mid = (nl + nr)>>1;
    if (cur <= mid) {
        DoUpdate(cur, val, root<<1, nl, mid);
    } else {
        DoUpdate(cur, val, root<<1|1, mid + 1, nr);
    }
    PushUp(root);
}
void Update(int index, int val) 
{
    DoUpdate(index, val, 1, 0, top - 1);
}
int* fallingSquares(int** positions, int positionsSize, int* positionsColSize, int* returnSize){
    *returnSize = positionsSize;
    if (positionsSize <= 0) {
        return NULL;
    }
    int arryLen = positionsSize*2;
    int *arry = (int *)malloc(arryLen*sizeof(int));
    memset(arry, 0, arryLen*sizeof(int));
    top = 0;
    for (int i = 0; i < positionsSize; i++) {
        InsertArry(arry, arryLen, positions[i][0]);
        InsertArry(arry, arryLen, positions[i][0] + positions[i][1] - 1);
    }
    //printf("top = %d\n", top);
    
    BuildTree(top);
    //printf("BuildTree  success\n");

    int* ans = (int *)malloc(positionsSize*sizeof(int));
    memset(ans, 0, positionsSize*sizeof(int));
    
    int indexL;
    int indexR;
    int heigh;
    int maxHeight = -1;
    int qL;
    int qR;
    for (int i = 0; i < positionsSize; i++) {
        indexL = FindArryIndex(arry, positions[i][0]);
        indexR = FindArryIndex(arry, positions[i][0] + positions[i][1] - 1);
        //printf("\n Query------\n");
        //printf("Query input: L =%d, R=%d \n", indexL, indexR);
        heigh = Query(indexL, indexR) + positions[i][1];
        printf("Query out  : base = %d heigh =%d  ph=%d\n", 
                            //heigh - positions[i][1], heigh, positions[i][1]);

        //printf("\n Update------\n");
        for (int j = indexL; j <= indexR; j++) {
            Update(j, heigh);
        }
        PritfTree();
        //printf("\n ANS   ------\n");
        int tmp = Query(0, top);
        printf("Update&Query out: %d\n", tmp);
        if (tmp > maxHeight) {
            maxHeight = tmp;
        }
        ans[i] = maxHeight;
    }
    free(arry);
    free(tree);
    return ans;

}
/**
int main()
{
    int **positions;
    int size = 3;
    int *colSize;
    int retSize = 0;
    int *ret;

    positions = (int **) malloc(size * sizeof(int *));
    colSize = (int *) malloc(size*sizeof(int));
    for (int i = 0; i < size; i++) {
        positions[i] = (int *) malloc(2*sizeof(int));
        colSize[i] = 2;
    }
    positions[0][0] = 1;
    positions[0][1] = 2;

    positions[1][0] = 2;
    positions[1][1] = 3;

    positions[2][0] = 6;
    positions[2][1] = 1;

    ret = fallingSquares(positions, size, colSize, &retSize);
    printf("[");
    for (int i = 0; i < retSize; i++) {
        printf(" %d", ret[i]);
    }
    printf("]\n");
    free(ret);
    free(colSize);
    for (int i = 0; i < size; i++) {
        free(positions[i]);
    }
    free(positions);
    system("pause");
    return 0;
}
*/