### 解题思路
![image.png](https://pic.leetcode-cn.com/459945a0a189f4aa530243e4f041e92d099c4956e8a1a99e72a8d9202cd50a1c-image.png)


题目的范围比较有限，数字从1到9产生组合。其可以产生的从1位数到9位数的组合总数可以看做是总计为9个bits的数的0,1组合分布。
我们把1-9，这9个数，分别用长度为9bits的一个数来映射，bits0代表选择1，bits8代表选择9。
例如：
000000001b，表示[1]
000000011b，表示[1,2]
100000011b，表示[1,2,9]

剩下的就是暴力求解了，9个bits的数，最大不超过512，（同理，如果是10个bits不超过1024）。
我们做一个i从1到512次的循环，取i中取值为1的bit位对应的数字，求和，看是否满足。


### 代码

```c
 #define MAX_VALUE 45
 #define MAX_COMBIN 512
 #define MAX_BITS 9

int CountBit1(int value)
{
    int ret = 0;

    do {
        if ((value & 0x1 ) == 1) {
            ret++;
        }
        value = value >> 1;
    } while(value > 0);

    return ret;
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    int i,j,t;
    int **ret;
    int *retcol;
    int table[MAX_BITS] = {1,2,3,4,5,6,7,8,9};    
    int value=0;
    int *temp = malloc(sizeof(int)*k);
    
    if ((n > MAX_VALUE) || (k <= 0) || (n <= 0)) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 0;    
    ret = malloc(sizeof(int*)*MAX_COMBIN);
    memset(ret,0,sizeof(int*)*MAX_COMBIN);
    retcol = malloc(sizeof(int)*MAX_COMBIN);
    memset(retcol,0,sizeof(int)*MAX_COMBIN);

    for (i=1; i<MAX_COMBIN; i++) {
        if (CountBit1(i) == k) {
            //计算一下
            memset(temp,0,sizeof(int)*k);
            for (value=0, t=0, j=0; j<MAX_BITS; j++) {
                if ((i & (1<<j)) > 0) {
                    value += table[j];
                    temp[t++] = table[j];
                }
            }

            if (value == n) {
                //得到了一个可行的解
                ret[*returnSize] = malloc(sizeof(int)*k);
                memcpy(ret[*returnSize],temp,sizeof(int)*k);
                retcol[*returnSize] = k;
                *returnSize += 1;
            }
        }
    }

    *returnColumnSizes = retcol;    
    return ret;
}
```