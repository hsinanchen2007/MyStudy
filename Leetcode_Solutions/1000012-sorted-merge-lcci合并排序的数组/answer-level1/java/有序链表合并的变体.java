```
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        //类似两个有序链表的合并
        //从后往前，逆序
        while(m >0 && n > 0){
            //选大的赋值
            if(A[m-1] > B[n-1]){
                A[m+n-1] = A[m-1];
                m--;
            }else{
                A[m+n-1] = B[n-1];
                n--;
            }
        }
        //此使要么m != 0 要么n!=0
        //m != 0时，对应的数一定比之前的小，且已经在A中了，保持不动即可

        //n != 0时，更小的数在B中，需向A中迁移即可
        while(n > 0){
            // A[m+n-1] = B[n-1];
            //m == 0,可写为以下形式
            A[n-1] = B[n-1];
            n--;
        }

    }
}
```
