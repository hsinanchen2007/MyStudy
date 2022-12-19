
枚举所有可能，暴力破解。
直接上代码，自行阅读。关注点：
1. Point24()为入口，-> TravelAllCards()递归遍历所有数字组合。
2. -> GetValidCount() 遍历每次计算中5种括号形式。
3. -> Operate() 遍历每次计算中三个加减乘除的所有组合。
4. 以上两步中使用了回调函数，减少判断，应该还是比较好用。
5. breaker() 为调试断点 入口，一般不用关心。同各种组合输出一样，需要打开MY_DEBUG才有效。
6. Point24Main()和TranslateToNumber()无需关心，为了接口另外一套调试输入。


应该还是有些优化点，不折腾了，有好的建议，欢迎留言~


```c
//#define MY_DEBUG

#define MAX_CARDS   4

#define SWAP(a, b) do { temp = a; a = b; b = temp; } while (0)
#define ARRARY_COUNT(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef float (*FN_CALC) (float a, float b);
typedef struct _CALC_ITEM {
    char       flag;
    FN_CALC    fn;
} CALC_ITEM, *PCALC_ITEM;

typedef float (*FN_OP) (int *cards, PCALC_ITEM  *calc);
typedef struct _OP_ITEM {
    const char* fmt;
    FN_OP       fn;
} OP_ITEM, *POP_ITEM;

#ifdef MY_DEBUG
#define LOG(fmt, args...) fprintf(stderr, fmt, ##args)
#define BREAKER(a, b, c)  breaker(a, b , c)
#else
#define LOG(fmt, args...)
#define BREAKER(a, b, c)
#endif


float _add(float a, float b) { return a + b; };
float _sub(float a, float b) { return a - b; };
float _mul(float a, float b) { return a * b; };
float _div(float a, float b) { return a / b; };

float fn_op_21_1(int *cards, PCALC_ITEM *calc)
{
    // { "((%d %c %d) %c %d) %c %d", fn_op_21_1 },
    float result;
    result = calc[0]->fn((float)cards[0], (float)cards[1]);
    result = calc[1]->fn(result, (float)cards[2]);
    result = calc[2]->fn(result, (float)cards[3]);
    return result;
};

float fn_op_12_1(int *cards, PCALC_ITEM *calc)
{
    // { "(%d %c (%d %c %d)) %c %d", fn_op_12_1 },
    float result;
    result = calc[1]->fn((float)cards[1], (float)cards[2]);
    result = calc[0]->fn((float)cards[0], result);
    result = calc[2]->fn(result, (float)cards[3]);
    return result;
};

float fn_op_1_21(int *cards, PCALC_ITEM *calc)
{
    // { "%d %c ((%d %c %d) %c %d)", fn_op_1_21 },
    float result;
    result = calc[1]->fn((float)cards[1], (float)cards[2]);
    result = calc[2]->fn(result, (float)cards[3]);
    result = calc[0]->fn((float)cards[0], result);
    return result;
};

float fn_op_1_12(int *cards, PCALC_ITEM *calc)
{
    // { "%d %c (%d %c (%d %c %d))", fn_op_1_12 },
    float result;
    result = calc[2]->fn((float)cards[2], (float)cards[3]);
    result = calc[1]->fn((float)cards[1], result);
    result = calc[0]->fn((float)cards[0], result);
    return result;
};

float fn_op_2_2(int *cards, PCALC_ITEM *calc)
{
    // { "(%d %c %d) %c (%d %c %d)\n", fn_op_2_2 },
    float result1, result2;
    result1 = calc[0]->fn((float)cards[0], (float)cards[1]);
    result2 = calc[2]->fn((float)cards[2], (float)cards[3]);
    result1 = calc[1]->fn(result1, result2);
    return result1;
};

static inline int is24(float result)
{
    if (result > 23.999 && result < 24.0001)
        return 1;
    return 0;
}

static void breaker(int *cards, POP_ITEM op, PCALC_ITEM *calc){
    int break_value[] = {7, 7, 1, 1};
    FN_OP break_op_fn = fn_op_1_12;
    FN_CALC break_calc_fn[] = {_mul,_div,_add};
    if (break_op_fn != op->fn)
        return;
    for (int i = 0; i < MAX_CARDS; i++) {
        if (cards[i] != break_value[i])
            return;
    }
    for (int i = 0; i < ARRARY_COUNT(break_calc_fn); i++) {
        if (break_calc_fn[i] != calc[i]->fn)
            return;
    }
    return;
}

static int DoOperate(int *cards, POP_ITEM op, PCALC_ITEM *calc)
{
    float result;
    BREAKER(cards, op, calc);
    result = op->fn(cards, calc);
    if (is24(result)) {
        LOG(op->fmt, cards[0], calc[0]->flag, cards[1], calc[1]->flag, cards[2], calc[2]->flag, cards[3]);
        return 1;
    }
    return 0;
}

static int Operate(int *cards, POP_ITEM op)
{
    PCALC_ITEM calc[3];
    int validCount = 0;
    static CALC_ITEM calcAll[] = {
        {'+', _add},
        {'-', _sub},
        {'*', _mul},
        {'/', _div},
    };
    
    for (int i = 0; i < ARRARY_COUNT(calcAll); i++) {
        for (int j = 0; j < ARRARY_COUNT(calcAll); j++) {
            for (int k = 0; k < ARRARY_COUNT(calcAll); k++) {
                calc[0] = &calcAll[i];
                calc[1] = &calcAll[j];
                calc[2] = &calcAll[k];
                validCount += DoOperate(cards, op, calc);
            }
        }
    }
    return validCount;
}

static int GetValidCount(int *cards)
{
    int validCount = 0;
    static OP_ITEM ops[] = {
        { "((%d %c %d) %c %d) %c %d\n", fn_op_21_1 },
        { "(%d %c (%d %c %d)) %c %d\n", fn_op_12_1 },
        { "%d %c ((%d %c %d) %c %d)\n", fn_op_1_21 },
        { "%d %c (%d %c (%d %c %d))\n", fn_op_1_12 },
        { "(%d %c %d) %c (%d %c %d)\n", fn_op_2_2 },
    };
    for (int i = 0; i < ARRARY_COUNT(ops); i++) {
        validCount += Operate(cards, &ops[i]);
    }
    return validCount;
}

static int TravelAllCards(int *cards, int len, int index)
{
    int temp;
    int validCount = 0;
    if (index >= len) {
        return GetValidCount(cards);
    }
    for (int i = 0; i < MAX_CARDS; i++) {
        SWAP(cards[index], cards[i]);  // swap every card to first.
        validCount += TravelAllCards(cards, len, index + 1);
        SWAP(cards[index], cards[i]);  // restore swapped every card.
    }
    return validCount;
}

static int Point24(int *cards, int len)
{
    int validCount;
    if (len != MAX_CARDS) {
        LOG("invalid input length: %d\n", len);
        return -1;
    }
    validCount = TravelAllCards(cards, len, 0);
    LOG("total %d valid anwser.\n", validCount);
    return validCount;
}

static int TranslateToNumber(const char *in, int *cards, int len)
{
    static const char *validInputs = "A23456789TJQK";
    for (int i = 0; i < len; i++) {
        const char *p = strchr(validInputs, in[i]);
        if (p == NULL) {
            return -1;
        }
        cards[i] = (p - validInputs) + 1;
    }
    return 0;
}

static void Display(int validCount)
{
    printf((validCount > 0) ? "Yes\n" : "No\n");
}

int Point24Main(const char *in, int len)
{
    int cards[4], ret;
    if (len != MAX_CARDS) {
        LOG("invalid input length: %d\n", len);
        return -1;
    }
    ret = TranslateToNumber(in, cards, MAX_CARDS);
    if (ret < 0) {
        LOG("invalid input: [%s]\n", in);
        return -1;
    }
    ret = Point24(cards, len);
    Display(ret);
    return ret;
}


bool judgePoint24(int* nums, int numsSize){
    return (Point24(nums, numsSize)>0) ? true : false;
}

```
