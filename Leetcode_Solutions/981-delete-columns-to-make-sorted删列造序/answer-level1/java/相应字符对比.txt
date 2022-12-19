### 解题思路
因为每个字符串的长度相同，我们就将相应位置的字符进行对比，时间复杂度为O(LN), L为字符串长度, N为元素个数。

### 代码

```java
class Solution {
    public int minDeletionSize(String[] A) {
        int D = 0;
        for(int i = 0; i < A.length; i++){
            A[i] = A[i].trim();
        }
        int N = A[0].length();
        for(int i = 0; i < N; i++){
            for(int j = 0; j < A.length - 1; j++){
                if(A[j].charAt(i) > A[j + 1].charAt(i)){
                    D++;
                    break;
                }
            }
        }
        return D;
    }
}
```