### 解题思路
也是数据结构书上看到的，本来想用插入排序，发现这种尾插法更优化（对这题而言）。

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int length=m+n;
        for(int i=length-1;i>=0;i--)
        {
            if(m>0 && n>0)
            {    
                if(A[m-1]<B[n-1])           //比较AB最大值的大小，B更大则.....
                {
                    A[i]=B[--n];
                }else                      //A更大
                {
                    A[i]=A[--m];
                }
        
            }else if(n>0 && m==0)
            {
                A[i]=B[--n];
            }
        }
    }
}
```