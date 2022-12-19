# 合并排序的数组
# 思路
双指针，倒序遍历即可
# 代码
```
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int p1=m-1,p2=n-1,p=m+n-1;
        while(p1>=0 && p2>=0)
        {
            if(A[p1]>=B[p2])
            {
                A[p--]=A[p1--];
            }
            else
            A[p--]=B[p2--];
        }
        while(p1>=0 || p2>=0)
        {
            if(p1>=0)
            A[p--]=A[p1--];
            else
            A[p--]=B[p2--];
        }
    }
}
```
- 时间复杂度：O(m+n)，指针移动次数
- 空间复杂度:O(1),直接对原数组进行修改的
