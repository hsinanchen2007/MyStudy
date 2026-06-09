### 解题思路
1、如果三等分数组，则说明该数组元素之和可以被3整除。
2、若不能被3整除，根本不可能存在
3、可以被3整除，则遍历数组
4、和为数组之和的三分之一时，则标记+1，若找到2组，也就over了！

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;//记录数组元素之和
        for(int val : A){
            sum += val;
        }
        //如果总和不能被3整除，则存在的可能性为0
        if(sum % 3 != 0){
            return false;
        }

        sum /= 3;//每段的元素之和
        int count = 0;//记载段数
        int curSum = 0;//记载当前和
        for(int i = 0; i < A.length - 1; i++){
            curSum += A[i];
            if(curSum == sum){
                count++;
                if(count ==2){
                    return true;
                }
                curSum = 0;
            }
        }
        return false;
    }
}
```