### 解题思路
此处撰写解题思路
错误提交
1次：没有考虑b数组为空
2次：由于while大循环里又写了while循环 其实没有必要，

时间复杂度为o(m+n)
空间复杂度为o(m+n)


### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int pl1=0,pl2=0,pr1=m,pc=0;
        int c[]=new int[m+n];
        while(pl1<m&&n!=0&&m!=0&&pl2<n)
        {
            if(A[pl1]<=B[pl2]&&pl1<m)
          {
            c[pc++]=A[pl1];
            pl1++;
          }  
            if(A[pl1]>B[pl2]&&pl2<n)
            {
                c[pc++]=B[pl2];
                pl2++;
            }

        }
        while(pl1<m) c[pc++]=A[pl1++];
        while(pl2<n) c[pc++]=B[pl2++];
        for( int i=0;i<m+n;i++)
        A[i]=c[i];
    }
}
```