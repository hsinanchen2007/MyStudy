使用两个变量分别指向两个数列的队尾，然后挨个比较队尾数据的大小，将大的数据插入到buffer中。

void merge(int* A, int ASize, int m, int* B, int BSize, int n)
{
    int pa = m - 1;
    int pb = n - 1;
    int l = m + n - 1;  /* 队列总长度 */

    while ((pa >= 0) || (pb >= 0)) {
        if (pa < 0) {
            A[l] = B[pb];
            pb--;
        } else if (pb < 0) {
            A[l] = A[pa];
            pa--;
        } else if (A[pa] > B[pb]) {
            A[l] = A[pa];
            pa--;
        } else {
            A[l] = B[pb];
            pb--;
        }
        l--;
    }

    return;
}