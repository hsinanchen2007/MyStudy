### 解题思路
1、先将对应整数转出成由低位到高位顺序数组存放、并备份
2、将数组每位上数字排序，原始数据和排序数字最由高位到低位比较，找到不等地方进行交换 计算。


### 代码

```c
#define MAX(a, b) (a > b ? a:b)
int cmp(void* a, void* b) 
{
    int* a1 = (int*)a;
    int* b1 = (int*)b;
    return (*a1 - *b1);
}
int findDigtalPosition(int* nums, int val, int len) 
{
    int i = -1;
    for (i = 0; i < len; i++) {
        if(nums[i] == val) {
            return i;
        }
    }
    return i;
}
int maximumSwap(int num){
    int tmp = num;
    int val = 0;
    int k = 0;
    int i;
    int pos;
    int digtal[10] = {0};
    int digOrg[10] = {0};
    if (num <= 0) {
        return 0;
    }
    while (tmp) {
        digtal[k++] = tmp%10;
        tmp = tmp/10;
    }
    memcpy(digOrg,digtal,sizeof(digOrg));
    qsort(digtal, k, sizeof(int), cmp);
    //digtal里面数据用于从小到大排序，从高位到低位比较，如果不一致就记录位置，表明此处数据交换会使结果最大
    for (i = k-1; i > 0; i--) {
        if (digtal[i] != digOrg[i]) { 
            break;
        } 
    }
    if (i == 0) {
        return num;
    }
    else { // 找到对应不相等的位置，然后将大数据防高位，原来高位数据找到之前位置进行交换
        tmp = digOrg[i];
        pos =  findDigtalPosition(digOrg, digtal[i],i);
        digOrg[i] = digtal[i];
        digOrg[pos] = tmp;

    }
    for (i = k-1; i >= 0; i--) {
        val = val*10+ digOrg[i];
    }
    return val;
}
```