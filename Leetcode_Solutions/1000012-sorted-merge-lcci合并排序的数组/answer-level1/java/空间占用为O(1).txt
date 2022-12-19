### 解题思路
空间占用为O(1)，选最大的放到最右。


### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        if(n>0){
            int a=m-1;
            int b=n-1;
            for(int i=m+n-1;i>=0;i--){
                if(a==-1){
                    a=0;
                    A[0]=B[0];

                }
                if(b==-1){
                    b=0;
                    B[0]=A[0];
                }
                if(A[a]>=B[b]){
                    A[i]=A[a];
                    a--;
                }else{
                    A[i]=B[b];
                    b--;
                }


            }


        }
       
        

    }
}
```