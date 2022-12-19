### 解题思路
参考：
作者：asentry
链接：https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/solution/cyu-yan-by-asentry-5/

同时在原基础上增加遍历元素个数统计，优化后可提前退出，不用遍历到第80000个元素。
执行结果：
通过
显示详情
执行用时 :52 ms, 在所有 C 提交中击败了94.68%的用户
内存消耗 :8.3 MB, 在所有 C 提交中击败了100.00%的用户

### 代码

```c

#define HASH_VALUE_SIZE 80000   // 注意此值要大于40000, 如果最大数正好为40000，那么往后操作还要向后累加的
int gHash[HASH_VALUE_SIZE] = { 0 };

int Compare(void *a, void *b) 
{
    return (*(int *)a) > (*(int *)b);   // 升序排序
}

int GetNextAvailableNum(int a)
{   
    for (int i = a + 1; i < HASH_VALUE_SIZE; i++) {
        if (gHash[i] == 0) {
            return i;
        }
    }
    return -1;
}

/*
执行结果：
通过
显示详情
执行用时 :
2112 ms, 在所有 C 提交中击败了5.32%的用户
内存消耗 :9.1 MB, 在所有 C 提交中击败了100.00%的用户
*/
int minIncrementForUnique1(int* A, int ASize){
    if (A == NULL) {
        return 0;
    }
    // init
    memset(gHash, 0, sizeof(gHash));
    qsort(A, ASize, sizeof(int), Compare);  // 快速排序，升序
    int sum = 0;
    for (int i = 0; i < ASize; i++) {
        if (gHash[A[i]] == 0) { // A[i]不重复
            gHash[A[i]] = 1;    // Hash表置标记
        } else {    // 重复元素
            int targetNumber = GetNextAvailableNum(A[i]);   // 找下一个不重复数：目标数
            if (targetNumber != -1) {
                gHash[targetNumber] = 1;    // 更新哈希表，置标记
                sum += targetNumber - A[i]; // 累加操作次数
            } else {    // 超过数组限制大小，防止数组越界
                printf("error %d\n", A[i]);
            }
        }        
    }   
    return sum;
}

/*
参考了作者：asentry的解法。不使用qsort，重复元素后移累加置标记。

作者：asentry
链接：https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/solution/cyu-yan-by-asentry-5/

执行结果：
通过
显示详情
执行用时 :52 ms, 在所有 C 提交中击败了94.68%的用户
内存消耗 :8.3 MB, 在所有 C 提交中击败了100.00%的用户
*/

        
int minIncrementForUnique(int* A, int ASize){
    if (A == NULL) {
        return 0;
    }
    // init
    memset(gHash, 0, sizeof(gHash));
    // qsort(A, ASize, sizeof(int), Compare);  // 快速排序，升序
    for (int i = 0; i < ASize; i++) {
        gHash[A[i]]++;  // Hash表置标记,记录重复元素个数      
    }
    int sum = 0;
    int movedCnt = 0;
    for (int i = 0; i < HASH_VALUE_SIZE; i++) {
        if(gHash[i] > 1) {   // 有重复元素
            gHash[i+1] += gHash[i] - 1;  // 需要后移操作的元素个数 : gHash[i]-1 个元素要后移到下一位置 
            sum += gHash[i] - 1;
            gHash[i] = 1;
        } 
        if (gHash[i] != 0) {    // 优化，通过movedCnt记录当前已经处理过的元素个数，如果超过ASize 可提前退出
            movedCnt++;
            if (movedCnt >= ASize) {
                break;
            }
        }    
    }   
    return sum;
}



```