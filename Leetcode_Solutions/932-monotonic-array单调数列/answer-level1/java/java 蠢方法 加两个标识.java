### 解题思路
将递增和递减分别用2 1表示，在前后两个数不等的时候判断是否合法就行了

### 代码

```java
class Solution {
    public boolean isMonotonic(int[] A) {
        if(A.length == 1|| A.length == 2) return true;
        for(int i = 1, s = 0; i <A.length;i++){
            if(A[i]!=A[i - 1]){
                if(s == 0) s = A[i - 1] > A[i] ? 1 : 2;
                if(s == 1 && A[i - 1] < A[i]) return false;
                if(s == 2 && A[i - 1] > A[i]) return false;    
            }
        }
        return true;
    }
}
```