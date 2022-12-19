/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define EX_MAX_NUM   1100
typedef struct {
    int w;
    int k;
} ChildInfo;

int FuncComp(const void *a, const void *b)
{
    ChildInfo *c = (ChildInfo*)a;
    ChildInfo *d = (ChildInfo*)b;
    if (c->w != d->w) {
        return (c->w - d->w);//从小到大
    } else {
        return (d->k - c->k);//必须从大到小
    }
}

void Exchange(ChildInfo *a, ChildInfo *b)
{
    ChildInfo temp;
    memcpy(&temp, a,sizeof(ChildInfo));
    memcpy(a, b,sizeof(ChildInfo));
    memcpy(b, &temp,sizeof(ChildInfo));
}


int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes)
{
    int i,j;
    ChildInfo child[EX_MAX_NUM];
    int** res = (int**)malloc(sizeof(int*) * peopleSize);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * peopleSize);//
    for(i =0;i<peopleSize;i++){
        child[i].w=people[i][0];
        child[i].k=people[i][1];
    }
    qsort(child, peopleSize, sizeof(ChildInfo),FuncComp);
    int temp = 0;
    for(i=(peopleSize-2);i>=0;i--){
        temp = child[i].k;
        for(j=0;j<temp;j++){
            Exchange(&child[i+j],&child[i+j+1]);
        }
    }
    *returnSize = peopleSize;
    for(i=0;i < peopleSize;i++){
        res[i]=(int*)malloc(sizeof(int)*2);        
        res[i][0] = child[i].w;
        res[i][1] = child[i].k;
        (*returnColumnSizes)[i]= 2;
    }
    return res;
}