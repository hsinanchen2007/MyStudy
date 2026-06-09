### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean validMountainArray(int[] A) {
        if(A.length<3)return false;
        int max=0,k=0,flag=0;
    for(int i=0;i<A.length;i++){
        if(A[i]>max){
            max=A[i];
            k=i;
        }
    }
    if(k==A.length-1||k==0)return false;
    for(int i=0;i<k;i++){
        if(A[i]>=A[i+1])
        flag=1;
    }
    for(int i=k;i<A.length-1;i++){
        if(A[i]<=A[i+1])
        flag=1;
    }
    return flag==0;
    }
}
```