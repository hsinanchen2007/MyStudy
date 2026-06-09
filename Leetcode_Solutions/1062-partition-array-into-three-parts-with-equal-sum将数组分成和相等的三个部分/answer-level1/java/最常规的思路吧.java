### 解题思路
此处撰写解题思路
基本是最常规的解题思路吧，先判断总和能否被3整除，然后再第一个区间的总和是否为sum/3,接着再判断第二个，剩下的就不用判断了
### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0,avg = 0,sum1 = 0, sum2 = 0;
        for(int i = 0; i < A.length; i++)
            sum += A[i];
        if( sum % 3 != 0 )
            return false;
        avg = sum /3;
        for( int i = 0; i < A.length-2; i++){
            sum1 += A[i];
            if(sum1 == avg){
                for( int j = i+1; j < A.length-1; j++){
                    sum2 += A[j];
                    if( sum2 == avg)return true;
                }
            }
            
        }
        return false;
    }
}
```