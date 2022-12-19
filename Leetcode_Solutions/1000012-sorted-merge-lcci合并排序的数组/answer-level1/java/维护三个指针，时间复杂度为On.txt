### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {

        int a_index=m-1;
        int b_index=n-1;
        int total=m+n-1;

        while((a_index>=0||b_index>=0)&&total>=0){
            if(a_index<0){
                A[total]=B[b_index];
                b_index--;
                total--;
                continue;
            }
            if(b_index<0){
                A[total]=A[a_index];
                a_index--;
                total--;
                continue;
            }

            if(A[a_index]>B[b_index]){
                A[total]=A[a_index];
                a_index--;
                total--;
            }else{
                A[total]=B[b_index];
                b_index--;
                total--;
            }
        }

    }
}
```