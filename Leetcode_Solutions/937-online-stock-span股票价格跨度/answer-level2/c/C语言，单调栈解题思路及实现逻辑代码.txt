/**
 * 审题
 * 给的三个函数，都是工具函数。
 * stockSpannerCreate函数：该函数应该只调用一次，是创建存储price的内存。（所以要够大）
 * stockSpannerNext函数：注意，该函数是关键，这个函数不是让你计算一个数组，而是，让你去增加1天并且返回这一天在你添加的全部
 * stockSpannerFree函数：释放你之前所申请的全部内存。
 * 思路：递增单调栈
 * 1）申请一个全局的单调栈，要足够大。定义一个全局gIndex，为数组下标，递增
 * 2）栈为空时，说明前是首个元素，返回1直接。当栈不为空时，循环到栈为空或者price >= obj[stack.top].indexPrice->stack.pop->栈为空，说明大于前方一切，所以index -0；反之index - stack.top
 * 注：答案仅为逻辑代码，栈实现代码需要自行实现
 **/

```

#define MAX_N       10001

STACK_S* gStack = NULL;
int gIndex = 0;

StockSpanner* stockSpannerCreate() {
    gStack = (STACK_S *)malloc(sizeof(STACK_S));
    if (gStack == NULL) {
        return NULL;
    }
    memset(gStack, 0, (sizeof(STACK_S)));

    StackInit(gStack, MAX_N);

    StockSpanner* obj = (StockSpanner*) malloc(sizeof(StockSpanner*) * MAX_N);
    if (obj == NULL) {
        return NULL;
    }
    memset(obj, 0, (sizeof(StockSpanner*) * MAX_N));
    gIndex = 0;

    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int result = 0;

    while (!StackIsEmpty(gStack)) {
        if (obj[StackGetTop(gStack)].indexPrice  <= price) {
            //printf("\r\n*******gIndex = %d, obj[gIndex].indexPrice = %d, price = %d", gIndex, obj[gIndex].indexPrice, price);
            int tmp = 0;
            StackPop(gStack, &tmp);
        } else {
            break;
        }
    }

    if (StackIsEmpty(gStack)) {
        result = gIndex + 1 - 0;
    } else {
        result = gIndex + 1 - StackGetTop(gStack);
    }

    gIndex++;
    StackPush(gStack, gIndex);
    obj[gIndex].indexPrice = price;

    return result;
    
}

void stockSpannerFree(StockSpanner* obj) {
    if (obj != NULL) {
        free(obj);
    }

    if (gStack != NULL) {
        StackDestory(gStack);
    }

    return;
}

```


