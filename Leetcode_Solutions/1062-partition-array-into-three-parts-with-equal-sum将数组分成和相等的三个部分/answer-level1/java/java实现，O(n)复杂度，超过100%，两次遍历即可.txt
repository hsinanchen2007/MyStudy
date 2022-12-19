### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {

        int sum = 0;
        for(int i=0; i<A.length; i++){
            sum += A[i];
        }

        //如果总和不能被3除尽，说明肯定不能分成等和的3部分
        //如果能被3除尽，也不能说明可以返回true，比如：3,6,9，能被3除尽，但不能分成等和的3部分
        if(sum % 3 != 0) return false;

        //每一部分的和
        int part = sum / 3;
        sum = 0;
        int num = 0;
        for(int i=0; i<A.length; i++){
            sum += A[i];
            //等于每一部分的和之后，重置为0，重新开始
            if(sum == part){
                num++;
                sum = 0;
                //当num为3时，说明总和3部分的总和已经等于数组的总和了，剩下的加起来肯定为0，所以不
                //用继续遍历了
                if(num == 3){
                    return true;
                }
            }
        }
      
        return false;
    }
}
```