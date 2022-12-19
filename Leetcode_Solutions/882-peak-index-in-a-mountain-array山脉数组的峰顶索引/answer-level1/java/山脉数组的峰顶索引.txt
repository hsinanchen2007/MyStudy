### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int flag=0,len=0;
        for(int i=1;i<A.length-1;i++){
            flag=0;len=0;
           for(int j=0;j<i;j++){
               if(A[j]>A[j+1]){
                 flag=1;
                 break;
               }
           }
           if(flag==0){
               for(int j=i;j<A.length-1;j++){
                   if(A[j]<A[j+1]){
                       len=1;
                   }
               }
           }
           if(len==0){
               return i;
           }
        }
        return 0;
    }
}
```