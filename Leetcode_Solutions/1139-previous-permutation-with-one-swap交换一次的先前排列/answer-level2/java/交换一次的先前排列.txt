### 解题思路
此处撰写解题思路
### 代码

```java
class Solution {
    public int[] prevPermOpt1(int[] A) {
      int number=0,k=-1,h=-1,max=Integer.MIN_VALUE,t;
      for(int i=A.length-1;i>0;i--){
          if(A[i-1]>A[i]){
              k=i-1;
              break;
          }
      }
      if(k==-1)return A;
      for(int i=k+1;i<A.length;i++){
          if(A[i]>max&&A[i]<A[k]){
          max=A[i];
          h=i;
          }
      }
      if(k!=-1&&h!=-1){
      t=A[k];
      A[k]=A[h];
      A[h]=t;
      }
      return A;
    }
}
```