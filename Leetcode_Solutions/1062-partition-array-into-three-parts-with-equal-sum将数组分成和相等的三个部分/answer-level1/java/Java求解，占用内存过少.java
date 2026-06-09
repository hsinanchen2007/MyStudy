### 解题思路
定义一个flag作为划分标志，题目要求是划分三段，dividesum代表数组和的三分之一，遍历数组，当flag的值等于2时，说明两段已经达到三分之一和了，然后如果数组没有遍历完，说明已经成功实现了。

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
    int sum = 0;
        for (int i = 0; i < A.length; i++) {
            sum = sum + A[i];
        }
        int dividesum = sum / 3;
        int reg = sum % 3;
        int firstsum = 0;
        int i = 0;
        int flag = 0;
        if (reg == 0) {
            for (i = 0; i < A.length; i++) {
                int first = firstsum + A[i];
                if (first != dividesum) {
                    firstsum = first;
                } else {
                    firstsum = 0;
                    flag++;
                    if(flag == 2 && i<A.length-1){
                        {
                             return true;
                        }
                        
                    }
                }
            }
        }
        return false;

    }
}
```