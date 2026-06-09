### 解题思路
第一次碰到这么简单的题记录一下！
我的思路是：先求出总和，再从头开始递减，减到第一部分与剩余的呈1:2的比例，再对余下的部分判断能否呈1:1的比例。

### 代码

```java

class Solution {
    public boolean canThreePartsEqualSum(int[] A) {

        int sum = 0;
        for (int i = 0; i < A.length; i++) {
            sum += A[i];
        }
        int tmp = 0;
        for (int i = 0; i < A.length; i++) {
            tmp += A[i];
            sum -= A[i];
            if (sum == 2 * tmp){
                int tmp2 = 0;
                for (int j = i+1; j < A.length - 1; j++){
                    tmp2 += A[j];
                    if (sum == 2*tmp2) return true;
                }
            }
        }
        return false;
    }
}
```