### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int fixedPoint(int[] A) {
       //线性搜索效率太低，可以进行二分搜索
       int l=0,r=A.length-1;
       while(l<r){
           int mid=(l+r)/2;
           if(A[mid]<mid)
                l=mid+1;
            else
                r=mid;
       }
       return A[l]==l? l:-1;
    }
}
```