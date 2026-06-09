解题分两种情况： 
1. k = 1: max = 最大子串
2. k >= 1: 
    1. 如果数组和>0：max = 最大后子串 + (k - 2)*数组和 + 最大前子串
    2. 如果数组和<=0：max = 最大后子串 + 最大前子串
    3. 最后max与最大子串做对比，取最大值
```
#define MOD 1000000007
#define MAX(a,b) (a) > (b) ? (a) : (b)
#define N 100000

long long MaxSub(int *a, int size)
{
    // 求最大子串
    long long maxEndNow = 0;
    long long maxSub = 0;
    for(int i = 0; i < size; i++) {
        maxEndNow = MAX(maxEndNow + a[i], 0);
        maxSub = MAX( maxSub, maxEndNow);
    }
    return maxSub;
}

int kConcatenationMaxSum(int* arr, int arrSize, int k){
    long long res, sum, i;
    long long  maxSub=0;
    long long  maxPre=0;
    long long  maxPost=0;  
    if((arr == NULL) || (arrSize == 0)) {
        return 0;
    }
    sum = 0;
    // 得到数组和
    for(i = 0; i < arrSize; i++) {
        sum = sum + arr[i];
    }
    // 得到最大前子串
    sum = 0;
    for(i = 0; i < arrSize; i++) {
        sum = sum + arr[i];
         maxPre = MAX( maxPre, sum);
    }
    // 得到最大后子串
    sum = 0;
    for(i = arrSize - 1; i >= 0; i--) {
        sum = sum + arr[i];
         maxPost = MAX( maxPost, sum);
    }
    // 得到最大子串
    maxSub = MaxSub(arr, arrSize);
    if(k == 1) {
        res =  maxSub;
    } else {
        if(sum > 0) {
            res =  maxPost + (k - 2) * sum +  maxPre;
        } else {
            res =  maxPost +  maxPre;
        }
        res = MAX(res,  maxSub);
    }
    return res % MOD;
}
```
