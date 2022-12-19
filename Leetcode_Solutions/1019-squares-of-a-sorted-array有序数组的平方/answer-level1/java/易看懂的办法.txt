### 解题思路
此处撰写解题思路
先求平方，再进行排序
### 代码

```java
class Solution {
    public int[] sortedSquares(int[] A) {
        if(A==null)return null;
        for(int i=0;i<A.length;i++)
        A[i]*=A[i];
        int temp=0;
        for(int j=1;j<A.length;j++){
            for(int z=0;z<A.length-j;z++){
                if(A[z]>A[z+1]){
                    temp=A[z];
                    A[z]=A[z+1];
                    A[z+1]=temp;
                }
            }
        }
        return A;
    }
}
```