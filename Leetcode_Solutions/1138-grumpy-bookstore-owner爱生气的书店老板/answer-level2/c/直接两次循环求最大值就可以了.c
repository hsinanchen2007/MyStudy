### 解题思路
找到第一个1，开始统计计数，如果计数到X，则计算出转换的最大值。
+没转换的值。

### 代码

```c
#define max(a,b) a>b?a:b
int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int X){

    int sum = 0;
    for(int i = 0 ; i < customersSize;i++)
    {
        if(grumpy[i] == 0) {
            sum += customers[i];
        }
    }

    int window[customersSize];
    for(int i = 0; i < customersSize; i++) {
       window[i] = 0;
    }
    int left = 0, right = 0;
    int angrycnt=0;
    int index = 0;
    int count = 0;
    int sumAngry = 0;
    int MaxSum = 0;
    for(int i = 0; i<customersSize;i++) {
        if(grumpy[i] == 1) {
             index = i;
             for(int k = i; k < customersSize; k++)
             {
                 count++;
                 if(grumpy[k] == 1) {
                     sumAngry+=customers[k];
                 }
                 if(count == X)
                 {
                     break;
                 }
             }
             MaxSum = max(MaxSum,sumAngry);
             sumAngry =0;
             count = 0;
        }
    }
    return sum + MaxSum;
}
```