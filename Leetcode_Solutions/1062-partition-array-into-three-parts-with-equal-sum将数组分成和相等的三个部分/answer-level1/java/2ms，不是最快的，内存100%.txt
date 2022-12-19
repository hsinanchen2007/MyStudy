### 解题思路

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for(int x: A){
            sum += x;
        }
        if(sum%3 != 0) return false;
        int val = sum/3, flag = 0;
        sum = 0;
        for(int i = 0; i < A.length; i++){
            sum += A[i];
            if(sum == val){
                sum = 0;
                flag++;
            }
        }
        return flag >= 3;
    }
}
```