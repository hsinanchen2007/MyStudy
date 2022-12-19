### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int smallestRangeI(int[] A, int K) {
        if(A.length==0)
            return 0;
        int min=A[0];
        int max=A[0];
        //找到最大值最小值
        for(int i=0;i<A.length;i++){
            if(A[i]<min)
                min=A[i];
            if(A[i]>max)
                max=A[i];
        }

        int x= K>=0?K:(-K);
        if((max-min)>(2*K))
            return max-min-2*K;
        return 0;
    }
}
```