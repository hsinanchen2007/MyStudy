### 解题思路
1.计算出数组的总和，总和不能被3整除的，直接返回false
2.i从数组头开始，j从数组尾开始移动，headSum累加到三分之一总和位置，tailSum累加到三分之一总和位置，如果能做到则返回true（此处有个条件是j-i必须大于1，因为数组得分为三段，如果i和j相差小于等于1，则不能将数组分为三段）
### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int total = 0;
        //求总和
        for (int i = 0; i < A.length; i++) {
            total += A[i];
        }
        //总和不能被3整除的，直接返回false
        if (total % 3 != 0) {
            return false;
        }
        int i = 0, j = A.length - 1, headSum = A[0], tailSum = A[A.length-1];
        //循环前置条件为j-i>1
        while (j-i>1) {
            //满足条件，直接返回true
            if (headSum == tailSum && headSum == total / 3) {
                return true;
            }
            if (headSum != total / 3) {
                headSum += A[++i];
            }
            if (tailSum != total / 3) {
                tailSum += A[--j];
            }
        }
        return false;
    }
}
```