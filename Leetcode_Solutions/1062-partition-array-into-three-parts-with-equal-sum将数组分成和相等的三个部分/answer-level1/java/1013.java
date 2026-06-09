### 解题思路
首先看总和能不能被3整除，如果不能，直接返回false.
如果能的话，只需要判断其中有没有连续两个区间可以满足总和== sum/3.
如果其中两段都满足，那么剩余的部分也肯定满足.
### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for(int num:A){
            sum += num;
        }
        if(sum % 3 !=0){
            return false;
        }
        sum /= 3;
        int curSum =0,cnt = 0;
        for(int i=0;i<A.length-1;i++){
            curSum += A[i];
            if(curSum == sum){
                cnt++;
                if(cnt==2){
                    return true;
                }
                curSum =0;//更新curSum重新计算
            }  
        }
        return false;
    }
}
```