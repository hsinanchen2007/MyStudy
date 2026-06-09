### 解题思路
如果三个数是等差数列,就判断他的后面三个数是不是也是等差数列,如果是的话,就说明这四个一起也是一个等差数列

### 代码

```java
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        if (A.length < 3) {
            return 0;
        }
        int result = 0;
        for (int i = 2; i < A.length; i++) {
            result += isEqualsDiffer(A,i);
        }
        return result;
    }

    public static int isEqualsDiffer(int[] A, int endIndex) {
        int count = 0;
            if(endIndex < A.length){
            if (A[endIndex] - A[endIndex - 1] == A[endIndex - 1] - A[endIndex - 2]) {
                count ++ ;
                count += isEqualsDiffer(A,endIndex+1);
            }
        }
        return count;
    }
}
```