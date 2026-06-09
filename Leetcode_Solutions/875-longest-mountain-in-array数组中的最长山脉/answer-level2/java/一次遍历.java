### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int longestMountain(int[] A) {
        if(A.length<3)
        return 0;
        int k=0,h=0,max=0,flag=0;
        for(int i=1;i<A.length-1;i++){
            if(A[i]>A[i-1]&&A[i]>A[i+1]){
                flag=1;
             for(int j=i-1;j>=0;j--){
                 if(j==0){
                     k=j;
                     break;
                 }
                 else if(A[j]<=A[j-1]){
                 k=j;
                 break;
                 }
             }
             for(int j=i+1;j<=A.length-1;j++){
                 if(j==A.length-1){
                     h=j;
                     break;
                 }
                 else if(A[j+1]>=A[j]){
                 h=j;
                 break;
                 }
             }
            }
           if(h-k+1>max)
           max=h-k+1;
        } 
        if(flag==0)
        return 0;
        return max;
    }
}
```