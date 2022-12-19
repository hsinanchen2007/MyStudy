### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxWidthRamp(int[] A) {
        if(A.length==0||A.length==1)
        return 0;
        int max=Integer.MIN_VALUE,number=0;
        for(int i=0;i<A.length;i++){
            number=0;
            for(int j=A.length-1;j>i;j--){
                if(A[j]>=A[i]){
                    number=j-i;
                    break;
                }
            }
            if(number>max)
            max=number;
        }
        return max;
    }
}
```