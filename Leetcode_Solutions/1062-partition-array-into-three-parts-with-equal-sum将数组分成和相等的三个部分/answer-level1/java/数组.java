### 解题思路
这一题要考虑充分全面才能ac啊。有几个测试用例都没想到

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        if(A.length < 3)
            return false;

        int sum = 0;

        for(int i = 0; i < A.length; i++){
            sum += A[i];
        }

        if(sum % 3 != 0)
            return false;
        
        sum /= 3;

        int count = 0, tmp = 0;
        for(int i = 0; i < A.length; i++){
            tmp += A[i];
            if(tmp < sum)
                continue;
            else if(tmp == sum){
                count += 1;
                tmp = 0;
            }else{
            }
        }
        if(count >= 3)
            return true;
        else
            return false;
    }
}
```