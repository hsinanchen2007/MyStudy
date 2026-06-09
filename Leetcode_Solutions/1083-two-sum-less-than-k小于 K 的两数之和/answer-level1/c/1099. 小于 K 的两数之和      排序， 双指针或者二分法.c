### 解题思路
给你一个整数数组 A 和一个整数 K，请在该数组中找出两个元素，使它们的和小于 K 但尽可能地接近 K，返回这两个元素的和。

如不存在这样的两个元素，请返回 -1。

 

示例 1：

输入：A = [34,23,1,24,75,33,54,8], K = 60
输出：58
解释：
34 和 24 相加得到 58，58 小于 60，满足题意。



### 代码

```c
#define MAX(a,b) ((a)>(b)?(a):(b))

int cmp(int* a, int* b){
    return *a - *b;
}
int a,b;
int twoSumLessThanK(int* A, int ASize, int K){

    int i, l, r, target, max = 0, mid;
    a = b = 0;
    qsort(A, ASize, sizeof(int), cmp);
#if 1
    for(i=0; i< ASize-1 && A[i] < K/2; i++){
        l = i+1;
        r = ASize - 1;
        target = K - A[i] - 1;
        //这个l <= r条件的二分法， 如果没有相等值。
        //最终A[r]肯定小于target；除非所有值都大于target,此时r等于 边界-1
        while (l <= r){
            mid = (l + r)/2;
            if(A[mid] == target)
                return K-1;
            else if (A[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        if(r == i){
            //printf("A[%d]=%d,%d,target=%d\n",r, A[r],A[r+1], target);
            r -= 1;
        }

        max = MAX(max,A[i]+A[r]);
    }
#else
    l = 0;
    r = ASize -1;
    while (l < r) {
        if(A[l]+A[r]>=K)
            r--;
        else{
            max = MAX(max, A[l]+A[r]);
            l++;
        }
    }

#endif

    if(max ==0 || max == A[0])
        return -1;
    else
        return max;

}
```