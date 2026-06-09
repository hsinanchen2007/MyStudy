### 解题思路
先计算数组之和，第一次遍历，找出第一部分，第一次判断i的值不能超过A.length-2，然后第二次遍历，找出第二部分，再判断i的值不能超过A.length-1

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0,i = 0,curSum = 0;
        for(int n : A){
            sum +=n;
        }
        for( i = 0;i<A.length;i++){
            curSum += A[i];
            if(curSum == sum/3){
                break;
            }
        }
        if(i >= A.length-2){
            return false;
        }
        for(i = i+1;i<A.length;i++){
            curSum +=A[i];
            if(curSum == 2*sum/3){
                break;
            }
        }
        if(i >= A.length-1){
            return false;
        }
        return true;
    }
}
```