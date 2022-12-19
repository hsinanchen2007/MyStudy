### 解题思路
1 用例不允许长度为0的分组
2 分组和为0时，可能有多种分割方法

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int total = 0;
        for(int i = 0; i < A.length; i++) {
            total += A[i];
        }

        if(total % 3 != 0) {
            return false;
        }

        int threshold = total / 3;
        int count = 0;
        int temp = 0;
        for(int j = 0; j < A.length; j++) {
            temp += A[j];
            if(temp == threshold) {
                temp = 0;
                count++;
                if(count == 3 && threshold == 0) {
                    break;
                }
            }
        }

        return count == 3;
    }
}
```