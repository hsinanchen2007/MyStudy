### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int[] num=new int[A.length];
        int k=0;
        for(int i=0;i<A.length;i++){
            if(A[i]%2==0)  num[k++]=A[i];
        }
        for(int i=0;i<A.length;i++){
            if(A[i]%2==1)  num[k++]=A[i];
        }
        return num;
    }
}
```