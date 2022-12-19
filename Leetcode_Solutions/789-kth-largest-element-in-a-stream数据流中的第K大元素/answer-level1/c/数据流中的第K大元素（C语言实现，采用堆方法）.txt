没人写C语言的题解吗？我来写一个吧。
最初用了简单粗暴的排序法，虽然通过了，但执行时间长达700ms，看了别人的题解用堆来解更省时。认真学习了一下堆之后，决定用C语言实现堆的基本方法，然后用堆来解决此问题。为了以后做类似的题目方便，尽量把代码写的像一个库，下次解类似的题目可以复用。


同时，我还想知道，C语言有没有堆的标准库，可以直接使用的？


```
#include <stdio.h>

typedef struct stHeapData {
    int Weight;
    void *data;
}HEAP_DATA_S;
typedef int (compare) (int father, int son) ;
typedef struct stHeap {
    int maxLen;     /* 堆数组的最大长度 */
    int len;        /* 堆数组的实际长度 */
    compare *cmp;   /* father > son : 大顶堆， father < son: 小顶堆 */
    HEAP_DATA_S *pstData;  /* 堆数组。使用权重+data的方式保存数据，便于扩展。 */
}HEAP_S;

/* 通过父子关系，判断你想到的是大堆还是小堆 */
int HeapCompreMax (int father, int son)
{
    if (father > son) {
        return 1;
    }else {
        return 0;
    }
}

int HeapCompareMin (int father, int son)
{
    if (father < son) {
        return 1;
    } else {
        return 0;
    }
}

/* 堆初始化：
1、maxlen为堆最大长度。
2、实际申请的内存比堆最大长度多申请一个单位，堆满时，插入数据需要此单元临时存放 
3、需要制定比较函数。大堆使用HeapCompreMax， 小堆使用HeapCompareMin。
*/
HEAP_S *HeapInit(int maxlen, compare *cmp)
{
    HEAP_S *pstHeap = NULL;
    if (maxlen == 0 || cmp == NULL) {
        return NULL;
    }

    pstHeap = (HEAP_S *)malloc (sizeof(HEAP_S));
    if (pstHeap == NULL) {
        return NULL;
    }
    /*  数组多留1个位置，堆满时放预插入的数据  */
    pstHeap->pstData = (HEAP_DATA_S *) malloc (sizeof (HEAP_DATA_S) * (maxlen + 1));
    if (pstHeap->pstData == NULL) {
        free (pstHeap);
        return NULL;
    }

    pstHeap->maxLen = maxlen;
    pstHeap->len = 0;
    pstHeap->cmp = cmp;

    return pstHeap;
}

/*
    自底向上调整：
    1、插入元素时，采用自底向上的调整方法。
    2、找到最后一个元素的父亲，比较大小，不满足堆序则交换顺序。
    3、每次交换完后，需要继续检查父亲是否满足堆序，即继续向上调整，直到堆顶。如果已经满足堆序，则不需要继续调整。
    4、父子关系为：parent(i) = floor((i - 1)/2)， left(i) = 2i + 1， right(i)  = 2i + 2
*/
void HeapShiftUp(HEAP_S *pstHeap, int startpos)
{
    int pos = startpos;
    int parent;
    HEAP_DATA_S stTmpData = {0};

    if (pstHeap == NULL) {
        return;
    }

    while (pos != 0) {
        parent = (pos - 1) / 2;
        if (!pstHeap->cmp(pstHeap->pstData[parent].Weight, pstHeap->pstData[pos].Weight)) {
            memcpy(&stTmpData, &pstHeap->pstData[parent], sizeof(HEAP_DATA_S));
            memcpy(&pstHeap->pstData[parent],  &pstHeap->pstData[pos], sizeof(HEAP_DATA_S));
            memcpy(&pstHeap->pstData[pos], &stTmpData, sizeof(HEAP_DATA_S));
            pos = parent;
        } else {
            break;
        }
    }
    
    return;
}

/* 堆插入：放到堆底，向上调整。两个特殊位置：
1、第一次插入时，直接放在0号位置。
2、堆满再次插入时，堆调整完后把最后一个位置清空。堆长度不能超过最大长度。*/
void HeapInsert(HEAP_S *pstHeap, HEAP_DATA_S *pstData)
{
    HEAP_DATA_S stTmpData = {0};

    if (pstHeap == NULL || pstData == NULL) {
        return;
    }

    /* 数组最大长度为pstHeap->maxLen + 1 */
    if (pstHeap->len > pstHeap->maxLen) {
        return;
    }
    /* 先放堆底，再排序。第一个不需要排序。 */
    memcpy(&pstHeap->pstData[pstHeap->len], pstData, sizeof(HEAP_DATA_S));
    if (pstHeap->len == 0) {
        pstHeap->len = 1;
        return;
    }

    HeapShiftUp(pstHeap, pstHeap->len);

    /* len累加。堆满时，len不需要累加，同时把多余的删除 */
    if (pstHeap->len == pstHeap->maxLen) {
        memset(&pstHeap->pstData[pstHeap->len], 0, sizeof(HEAP_DATA_S));
    } else {
        pstHeap->len++;
    }

    return;
}

/* 自顶向下调整：
1、堆弹出时，常用自顶向下调整方法。
2、找堆顶元素的两个儿子，按堆序找大儿子。堆顶元素跟大儿子按堆序比较，如果不满足堆序，则交换顺序。
3、每次交换完顺序，需要继续检查儿子，直到堆底。已经满足堆序，则不需要继续检查。
3、可能没有儿子：左儿子（pos * 2 + 1） >= 堆长度。不需要继续遍历了。
4、可能只有1个儿子：左儿子满足条件，但右儿子（pos*2 + 1） >= 堆长度，则父亲与左儿子比*/
void HeapShiftDown(HEAP_S *pstHeap, int startpos)
{
    int pos = startpos;
    int leftson;
    int rightson;
    int eldestson;
    HEAP_DATA_S stTmpData = {0};
    if (pstHeap == NULL || pstHeap->len == 0 || pstHeap->len == 1) {
        return;
    }

    while (pos < pstHeap->len) {
        leftson = pos * 2 + 1;
        rightson = pos * 2 + 2;
        
        /*  找大儿子，比大小，换位置。  */
        if (leftson >= pstHeap->len) {
            break;
        }

        if (rightson >= pstHeap->len) {
            eldestson = leftson;
        } else {
            if (pstHeap->cmp(pstHeap->pstData[leftson].Weight, pstHeap->pstData[rightson].Weight)) {
                eldestson = leftson;
            } else {
                eldestson = rightson;
            }
        }
        if (!pstHeap->cmp(pstHeap->pstData[pos].Weight, pstHeap->pstData[eldestson].Weight)) {
            memcpy(&stTmpData, &pstHeap->pstData[pos], sizeof(HEAP_DATA_S));
            memcpy(&pstHeap->pstData[pos], &pstHeap->pstData[eldestson], sizeof(HEAP_DATA_S));
            memcpy(&pstHeap->pstData[eldestson], &stTmpData, sizeof(HEAP_DATA_S));
        } else {
            break;
        }

        pos = eldestson;
    }

    return;
}

/* 删除：删除堆顶，用堆底元素填充堆顶，然后自顶往下调整。 */
HEAP_DATA_S *HeapPop(HEAP_S *pstHeap)
{
    HEAP_DATA_S *pstRetData = NULL;
    if (pstHeap == NULL || pstHeap->len == 0) {
        return NULL;
    }
    pstRetData = pstHeap->pstData[0].data;
    if (pstHeap->len == 1) {
        pstHeap->len = 0;
        memset(&pstHeap->pstData[0], 0, sizeof(HEAP_DATA_S));
        return pstRetData;
    }

    /* 堆底元素挪到堆顶 */
    memcpy(&pstHeap->pstData[0], &pstHeap->pstData[pstHeap->len - 1], sizeof(HEAP_DATA_S));
    memset(&pstHeap->pstData[pstHeap->len - 1], 0, sizeof(HEAP_DATA_S));
    pstHeap->len--;

    /* 堆重新排序: 从0号位置，向下重新调整 */
    HeapShiftDown(pstHeap, 0);

    return pstRetData;
}

typedef void (freedata) (void *) ;
/* 堆释放：注意，data为用户数据，需要调用者指定释放方法 */
void HeapFree(HEAP_S *pstHeap, freedata *func)
{
    if (pstHeap == NULL) {
        return;
    }
    if (func != NULL) {
        for (int i = 0; i < pstHeap->len; i++) {
            func(pstHeap->pstData[i].data);
        }
    }

    free(pstHeap->pstData);
    free(pstHeap);

    return;
}



typedef HEAP_S KthLargest;

void KthLargestInsert(KthLargest* obj, HEAP_DATA_S *pstData)
{
    if (obj->len == obj->maxLen) {
        if (pstData->Weight <= obj->pstData[0].Weight) {
            return;
        } else {
            HeapPop(obj);
        }
    }

    HeapInsert(obj, pstData);
    
    return;
}

/* 创建时，先初始化一个堆，然后逐个插入。本题目需要的是一个前k个最大元素中的最小值，所以需要一个最小堆，同时只有最大的k个元素可以入堆。
所以，插入时遵循以下原则：
1、堆不满时，可以插入
2、堆满时，如果小或等于堆顶，则不需要插入；如果比堆顶大，则堆顶弹出，再插入新数据 */
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) 
{
    KthLargest *pstHeap = NULL;
    HEAP_DATA_S stData = {0};

    if (nums == NULL) {
        return NULL;
    }
    pstHeap = HeapInit(k, HeapCompareMin);
    if (pstHeap == NULL) {
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        stData.Weight = nums[i];
        stData.data = NULL;

        KthLargestInsert(pstHeap, &stData);
    }

    return pstHeap;
}

/* 添加数据时，遵循的原则与kthLargestCreate相同。构造一个函数KthLargestInsert可以复用 */
int kthLargestAdd(KthLargest* obj, int val) 
{
    HEAP_DATA_S stData = {0};
    if (obj == NULL) {
        return 0;
    }

    stData.Weight = val;
    stData.data = NULL;
    KthLargestInsert(obj, &stData);
    
    return obj->pstData[0].Weight;
}

/* 释放数据。 堆数据中有个data指针，主要传入此内存的释放方法。本题中没有为data申请内存，内存释放函数传入NULL即可 */
void kthLargestFree(KthLargest* obj) 
{
    HeapFree(obj, NULL);
    return;
}


```