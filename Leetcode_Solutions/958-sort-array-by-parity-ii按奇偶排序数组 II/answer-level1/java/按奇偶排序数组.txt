### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sortArrayByParityII(int[] A) {
       int[]num=new int[A.length];
       int []sum=new int[A.length];
       int x=0,y=A.length-1,z=0;
       for(int i=0;i<A.length;i++){
           if(A[i]%2==0)
           num[x++]=A[i];
           else num[y--]=A[i];
       }
         x=0;y=A.length-1;
        while(x<A.length){
            sum[x++]=num[z++];
            sum[x++]=num[y--];
        }
        return sum;
    }
}
```