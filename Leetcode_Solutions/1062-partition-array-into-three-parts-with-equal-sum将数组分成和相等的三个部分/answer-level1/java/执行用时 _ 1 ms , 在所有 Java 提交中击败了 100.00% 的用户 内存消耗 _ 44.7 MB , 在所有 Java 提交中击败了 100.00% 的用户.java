### 解题思路
先遍历一次求平均值，然后再再遍历一次，每次相加的和等于平均值，就从0开始加。最后如果等于3次返回true，或者大于3次且平均值为0，也返回true。其他均为false。

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int len = A.length;
        if (len < 3) {
            return false;
        }
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += A[i];
        }
        int average = sum / 3;
        sum = 0;
        int count = 0;
        for (int i = 0; i < len; i++) {
            sum += A[i];
            if (sum == average) {
                count++;
                sum = 0;
            }
        }
        if ((count == 3)) {
            return true;
        }
        if (count > 3 && average == 0) {
            return true;
        }
        return false;
    }
}
```