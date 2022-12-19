### 解题思路
此处撰写解题思路

### 代码

```c
//求取最大公约数
int least_common_divisor(int min, int b)
{
    for(int i=min; i>=2 ;i--) {
        if (min%i == 0 && b%i == 0) {
            return i;
        }
    }
    return 0;
}

bool hasGroupsSizeX(int* deck, int deckSize){
    if (deckSize < 2) {
        return false;
    }

    int max = 10000;
    int arr[max];
    memset(arr, 0, 4*max);

    //统计不重复数个数
    int j = 0;
    for(int i=0; i<deckSize; i++) {
        if (arr[deck[i]]) {
            j++;
        }
        arr[deck[i]]++;
    }

    int min = 0;
    for(int i=0; i<max; i++) {
        //最小数
        if (arr[i] > 0 && (min == 0 || arr[i] < min)) {
            min = arr[i];
        }
    }
    
    //看是否存在最大公约数
    int leastCommonDivisor = min;
    for(int i =0; i<max; i++) {
        if (arr[i] >0 && arr[i] != min) {
            //求取最大公约数
            int d = least_common_divisor(min, arr[i]);
            if (d == 0) {
                //没有返回false
                return false;
            } else {
                //如果有
                if (d < leastCommonDivisor) {
                    //当前公约数，和最小数 取最小
                    if (leastCommonDivisor%d == 0) {
                        leastCommonDivisor = d;
                    } else {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}
```