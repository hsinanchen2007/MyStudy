### 解题思路
![image.png](https://pic.leetcode-cn.com/69be03ac58a656a13337e993345ef4a142ff250c185f348ceab4764526bad7fb-image.png)


把整数转换为数组，数组的每个记录从0到9分别表示个位数，百位数，千位数，万位数......

从小到大对该数组进行排序，是这个数组可以重构成的最大的数。

当然排序后变化了的位数不止一位，那么我们优先从最高位交换，始终让大一些的数位于高一些的位即可。

从最高位到最低位比较排序过的数据sorted[j]]和排序前的数组orign[j]，找到第一个不同的位j，只要让orign[j]这一位的取值变为更大的sorted[j]，就得到了我们需要的结果;
即：将orign[j]交换给从orign[0] 到 orign[j-1]之间第一个出现的等于sort[j]的位置，我们记为i，交换orign[i]和orign[j]即可(注意，i一定是从最低位到最高位找的第一个)。

【注意】431881应该交换为831841，而不是831481；

把这个地方的数字进行交换即可。注意，被交换

### 代码

```c
#define MAX_TABLE_LEN 9

int CompNum(const void *a, const void *b) 
{
    return *((int *)a) - *((int *)b);
}

int maximumSwap(int num){
    int tableOrg[MAX_TABLE_LEN]={0};
    int tableSort[MAX_TABLE_LEN]={0};
    int len = 0;
    int temp = 0;
    int i,j;

    if (num <= 11) {
        return num;
    }

    while(num > 0) {
        tableSort[len] = tableOrg[len] = num % 10;
        num = num / 10;
        len++;
    }

    //从小到大排
    qsort(tableSort,len,sizeof(int),CompNum);

    j = len;
    while (j-- > 0) {
        if (tableSort[j] > tableOrg[j]) {
            //找到了一个可以调整的数
            for(i=0; i<j; i++) {
                if (tableOrg[i] == tableSort[j]) {
                    tableOrg[i] = tableOrg[j];
                    tableOrg[j] = tableSort[j];
                    break;
                }
            }
            break;
        }
    }
    
    num = 0;
    for (i=len-1; i>=0; i--) {
        num = num*10 + tableOrg[i];
    }

    return num;
}

```