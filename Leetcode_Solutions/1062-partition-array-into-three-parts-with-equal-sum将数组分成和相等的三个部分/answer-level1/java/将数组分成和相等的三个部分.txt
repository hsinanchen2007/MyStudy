### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int count=0,flag=0,len=0,num=0,k=0;
for(int i=0;i<A.length;i++)
count+=A[i];
count/=3;
for(int i=0;i<A.length;i++){
    len+=A[i];
    if(len==count){
        flag=1;
        k=i;
        break;
    }
}
for(int i=k+1;i<A.length;i++){
    num+=A[i];
    if(num==count&&flag==1&&i<A.length-1)
    return true;
}
return false;
    }
}
```