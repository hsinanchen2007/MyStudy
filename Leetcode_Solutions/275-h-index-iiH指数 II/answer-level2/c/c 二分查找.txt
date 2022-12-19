题目有点绕，先理解清楚题目意思，利用题目给出的两段性，应采用二分查找。
步骤如下：
1. 第一步先确定h的范围：  0<h<citationsSize
2. 第二步二分：  h将0~citationsSize这个区间分为两部分，小于等于h的部分和大于h的部分。
- 解释：只要h满足，那么小于等于h的数一定满足，大于h的数不满足。
- 第三步条件：倒数第h个数大于等于h即可，即citations[citationsSize-mid]>=mid

```c []
int hIndex(int* citations, int citationsSize){
int l=0,r=citationsSize;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(citations[citationsSize-mid]>=mid)
            l=mid;
        else r=mid-1;
    }
    return l;
}




