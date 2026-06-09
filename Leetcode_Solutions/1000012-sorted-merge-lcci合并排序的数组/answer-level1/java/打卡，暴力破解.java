### 解题思路
因为两个数组都是排好序得，直接用两个数组最后一个比较，最大值放着A数组后面，小值不变，继续比较，最后B数组还有直接排到A数组上即可

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int i = m-1;
        int j = n-1;
        int k = m + n -1;
        while(i > -1 && j > -1 ){
            if(A[i]>B[j]){
                A[k--] = A[i--];
            }else{
                A[k--] = B[j--];
            }
        }
        while(j>-1){
            A[k--] = B[j--];
        }
    }
}
```