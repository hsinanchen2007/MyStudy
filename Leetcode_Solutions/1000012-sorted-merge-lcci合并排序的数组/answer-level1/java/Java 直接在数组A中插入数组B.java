``` java
public class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        if (n == 0) {
            return;
        } else {
            // a指针
            int indexa = 0;
            // b指针
            int indexb = 0;
            // m指针记录a的末尾位置
            while (indexa < m && indexb < n) {
                if (B[indexb] < A[indexa]) {
                    add(A,indexa,B[indexb]);
                    // 所有指针后移
                    indexb++;
                    indexa++;
                    m++;
                } else {
                    // a指针后移
                    indexa++;
                }
            }
            // m指针之后的部分全部是B数组
            while (indexb < n) {
                A[m] = B[indexb];
                m++;
                indexb++;
            }
        }
    }

    // 将b的元素添加到a里，a剩下部分后移
    public void add(int[] A, int start, int b){
        for (int i = A.length-1; i > start; i--) {
            A[i] = A[i-1];
        }
        A[start] = b;
    }

}
```
