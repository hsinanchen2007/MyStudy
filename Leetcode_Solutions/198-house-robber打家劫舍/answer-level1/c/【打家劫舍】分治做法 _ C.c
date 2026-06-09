**分治做法**

参考[邱天异的回答](https://www.zhihu.com/question/269813200)


> Solve(l,r) 对连续子序列[l,r]计算，返回四个整数值{A,B,C,D}，意义如下：
> A表示子序列中，不取用最左和最右元素的最大和。
> B表示子序列中，不取用最左元素的最大和。
> C表示子序列中，不取用最右元素的最大和。
> D表示子序列中，无条件的最大和。
> Solve(l,r)调用Solve(l,mid)得到{A1,B1,C1,D1}，调用Solve(mid+1,r)得到{A2,B2,C2,D2},则：
> A=max{A1+C2，B1+A2}
> B=max{A1+D2，B1+B2}
> C=max{D1+A2，C1+C2}
> D=max{D1+B2，C1+D2}
> 返回{A,B,C,D}即可。

```
typedef struct {
    int A;
    int B;
    int C;
    int D;
}M, *MM;

int max2(int a, int b)
{
    return a > b ? a : b;
}

MM f(int* nums, int l, int r)
{
    MM mm1, mm2, mm;
    mm1 = (MM)malloc(sizeof(M));
    mm2 = (MM)malloc(sizeof(M));
    mm = (MM)malloc(sizeof(M));
    int mid = (l + r) / 2;
    if (l == r) {
        mm->A = 0;
        mm->B = 0;
        mm->C = 0;
        mm->D = nums[l];
    }
    else {
        mm1 = f(nums, l, mid);
        mm2 = f(nums, mid + 1, r);
        mm->A = max2(mm1->A+mm2->C, mm1->B+mm2->A);
        mm->B = max2(mm1->A+mm2->D, mm1->B+mm2->B);
        mm->C = max2(mm1->D+mm2->A, mm1->C + mm2->C);
        mm->D = max2(mm1->D+mm2->B, mm1->C+mm2->D);
    }
    return mm;
}

int rob(int* nums, int numsSize){
    MM mm = (MM)malloc(sizeof(M));
    
    if (numsSize == 0)  return 0;
    if (numsSize == 1)  return nums[0];
    if (numsSize == 2)  return max2(nums[0], nums[1]);
    mm = f(nums, 0, numsSize - 1);
    return mm->D;
}
```



