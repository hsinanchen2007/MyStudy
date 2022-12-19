### 解题思路
大家都思路都差不多,关键是如何将这种思路更清晰简单的表示出来.
我引入了 state 变量,用来记录进行到了第几个分段.
当 state=2 (即进行到了第3个分段),且 s=avg (即第三个分段的和达到平均数) 时,返回true.

可以看出即使未遍历完A数组,提前返回true,也不影响结果.
如 [1,1,1,-2,2,3,-3] 这种情况.

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {

        int sum = 0;
        for (int i : A) { sum += i; }
        if(sum%3!=0) return false;
        int avg = sum / 3;

        int s = A[0];
        int stage = 0;

        for (int i = 1; i < A.length; i++) {
            
            if (s != avg) s += A[i];
            else {
                s = A[i];
                stage++;
            }
            if(s==avg && stage==2) return true;

        }
        return false;
    }

}
```