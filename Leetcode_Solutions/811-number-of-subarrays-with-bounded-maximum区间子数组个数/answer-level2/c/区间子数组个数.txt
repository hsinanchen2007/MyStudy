### 解题思路
    顺序遍历每一个数，每个数可能会出现以下几种情况：
    1. 比L小
    2. 介于L,R之间
    3. 比R大
    对于第一种情况令low加一，记录出现的第一种情况的数量。此时，上一个位置能够产生多少种答案，此处依然能够产生多少种答案（在上一位置的答案的基础上，末尾加上当前数字）。所以**当前位置能够产生答案的数量，等于上一个位置答案的数量**
    对于第二种情况，先令right加一，记录出现的第二种情况的数量，此时,以当前数字结尾能够产生的答案数量就是low+right,所以**当前位置能够产生答案的数量就是low+right的数量**
    对于第三种情况，导致前后分割，前面的就没有必要考虑了，重新计数，**清空low，right，与lres**

### 代码

```c
int numSubarrayBoundedMax(int* A, int ASize, int L, int R){
    int low = 0, right = 0, res = 0, lres = 0;
    for(int i = 0; i < ASize; ++i){
        if(A[i] < L){
            low++;
            res += lres;
        }
        if(A[i] >= L && A[i] <= R){
            ++right;
            lres = right + low;
            res += lres;
        }
        if(A[i] > R){
            low = 0;
            right = 0;
            lres = 0;
        }
    }
    return res;
}
```