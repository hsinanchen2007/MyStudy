### 解题思路
本题思路比较简单，就是先求 sum，然后双指针碰撞，向内收敛 求和，判断左右两区是不是相等，如果相等返回true ，最后剩下的肯定满足情况

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int i = 0, j = A.length - 1;
        int leftSum = A[0];
        int rightSum = A[A.length-1];
        int sum = 0;
        for (int k = 0; k < A.length; k++) {
            sum+=A[k];
        }
        if (sum%3!=0){
            return false;
        }
        while (i +1 < j) {
            if(leftSum==sum/3&&rightSum==sum/3){
                return true;
            }
            if (leftSum!=sum/3){
                leftSum+=A[++i];
            
            }
            if (rightSum!=sum/3){
                rightSum+=A[--j];
            }

        }
        return false;
    }
}
```