### 解题思路
先遍历数组，得到该数组的和，如果和是三的倍数，则该数组可能可以分为三等分，否则不可能，即return false;
而后计算数组的平均值，average，对数组进行再次遍历求和，每当sum == count * average时，则将count ++，该步操作表明能够在每次加上一个数后是否能得到average的倍数，只要count大于3则可表名该数组能被三等分

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        if(A == null || A.length == 0) return false;
        int sum = 0;
        for(int i : A) sum += i;
        if(sum % 3 != 0) return false;
        int average = sum/3;
        sum = 0;
        int i = 0, j = A.length - 1;
        int count = 1;
        for(int k = 0; k < A.length; k ++){
            sum += A[k];
            if(sum == count * average) count ++;
        }
        return count > 3;
    }
}
```