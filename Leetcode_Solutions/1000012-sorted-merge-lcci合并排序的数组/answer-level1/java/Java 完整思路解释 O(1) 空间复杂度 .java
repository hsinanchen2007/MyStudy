### 解题思路
为了避免额外的空间开销，提供一种奇奇怪怪的思路：
1. 先去找 $B$ 中第 $i$ 个元素应该放在 $A$ 的哪一个位置，计作 $pos$
2. 如果 $pos$ 超过了 $A$ 中已有的元素的最右端，即 $pos>=m+i$，那么就被 $B$ 中剩余的元素全部直接放进 $A$ 中剩余空间
3. 否则的话将 $A$ 中 $pos$ 以后的元素后移 $1$ 位，然后 $A[pos]=B[i]$

done!

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int t;
        for(int i=0;i<n;i++) {
            int pos = -1;
            for(int j=0;j<m+i;j++) {
                if(A[j]>B[i]) {
                    pos = j;
                    break;
                }
            }
            if(pos==-1) {
                pos = m+i;
                A[pos] = B[i];
                for(int j=i+1;j<n;j++) A[pos+j-i] = B[j];
                return;
            } else {
                for(int j=m+i;j>pos;j--) A[j] = A[j-1];
                A[pos] = B[i];
            }
        }
    }
}
```