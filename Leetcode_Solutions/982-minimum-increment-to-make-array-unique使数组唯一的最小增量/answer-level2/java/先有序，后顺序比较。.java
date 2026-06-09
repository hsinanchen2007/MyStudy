### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
        int move = 0;
    public int minIncrementForUnique(int[] A) {
  
       Arrays.sort(A);

        for(int i=1;i<A.length;i++){


                if(A[i-1]>=A[i]){
                    move = move+A[i-1]-A[i]+1;
                    A[i] = A[i-1]+1;
                  
                }

        }



        return move;
    }
}
```