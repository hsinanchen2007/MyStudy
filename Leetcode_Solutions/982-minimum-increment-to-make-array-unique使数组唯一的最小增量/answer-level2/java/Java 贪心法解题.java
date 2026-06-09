### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        if (A.length <= 1) return 0;
        Arrays.sort(A);
        int preNum = A[0];
        int count = 0;
        for(int i = 1; i < A.length; i++){
            if(A[i] >= preNum + 1){
                preNum = A[i];
            }else{
                count += preNum + 1 - A[i];
                preNum++;
            }
        }
        return count;
    }
}
```