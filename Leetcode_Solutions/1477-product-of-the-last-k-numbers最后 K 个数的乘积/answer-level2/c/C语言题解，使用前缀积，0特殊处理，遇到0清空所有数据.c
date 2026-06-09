```



/* 遇到0，清空数组，非0 使用前面的值乘以当前值，每个member[i] =  前i+1个元素的乘积*/
typedef struct {
  int multiNum;
} MemberInfo;
#define MAX_NUM 40000
typedef struct {
    MemberInfo member[MAX_NUM];
    int totalnum;
} ProductOfNumbers;


ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers* numlist = NULL;
    numlist = (ProductOfNumbers * )malloc(sizeof(ProductOfNumbers));
    memset(numlist, 0, sizeof(ProductOfNumbers));
    return numlist;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    int prim = 1;
    if (num == 0) {
        obj->totalnum = 0;
        memset(obj, 0, sizeof(ProductOfNumbers));
    } else {
        prim = (obj->totalnum == 0) ? ((int) 1) : (obj->member[obj->totalnum - 1].multiNum);
        obj->member[obj->totalnum].multiNum = prim * num;
        obj->totalnum++;
    }
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    if (k > obj->totalnum) {
        return 0;
    } else if (k == obj->totalnum) {
        return obj->member[obj->totalnum - 1].multiNum;
    }else {
        return obj->member[obj->totalnum - 1].multiNum / obj->member[obj->totalnum - k - 1].multiNum;
    }
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    (void)free(obj);
    obj = NULL;
}```
