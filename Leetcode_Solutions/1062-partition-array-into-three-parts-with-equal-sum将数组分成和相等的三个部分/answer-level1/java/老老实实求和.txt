### 解题思路
就暴力算。。一遍不行就再来一遍。。

先求出总和sum，如果sum不能被3整除，则false
然后找第一个1/3处和第二个1/3处，如果都找到了且还有剩余（第三部分不为空），则true，否则false

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        long sum = 0;
        for(int aa : A) {
            sum += aa;
        }
        if(sum % 3 != 0) {
            return false;
        }
        long part = sum / 3;
        long sum1 = 0;
        long sum2 = 0;
        boolean hasP1 = false;
        boolean hasP2 = false;
        int i = 0;
        for(; i<A.length; i++) {
            sum1 += A[i];
            if(sum1 == part) {
                hasP1 = true;
                break;
            }
        }
        for(i=i+1; i<A.length; i++) {
            sum2 += A[i];
            if(sum2 == part) {
                hasP2 = true;
                break;
            }
        }
        return hasP1 && hasP2 && i<A.length-1;
    }
}
```