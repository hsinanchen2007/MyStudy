### 解题思路
参考了 [C++ 双百，三根指针](https://leetcode-cn.com/problems/sorted-merge-lcci/solution/cshuang-bai-san-gen-zhi-zhen-by-deng-xian-sen-2/)的解法，很受启发。

这种解法对我来说难点还是边界情况的处理：indexA<0或indexB<0的时候如何如何处理？

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int indexA=m-1,indexB=n-1;
    int cur=m+n-1;

    //因为题目是要求将B加入到A中，所以结束的标志是B全部排列完
    while(indexB>=0){
        //同时还要考虑到indexA比indexB先到-1
        if(indexA<0){
            A[cur]=B[indexB--];
        } else if(A[indexA]>=B[indexB]){
            A[cur]=A[indexA--];
        } 
        else {
            A[cur]=B[indexB--];
        }
        cur--;
    }


}
```