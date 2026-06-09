### 解题思路
虽然提交了很多次才通过了，但是这道题本身并不难，只是提交的太冲动，没有思虑周详。
第一次循环，将所有值相加得到这个数组的和。因为要划分成三部分且和相等。所以它们的总和必定能被3整除，这个逻辑应该不难理解吧。如果不能被3整除就可以直接返回false了。
然后求平均值avg，立个flag表示有几部分的和等于avg。
然后循环，对值相加，当达到avg时，将临时和重置，flag加1。因为和为0情况特殊，正负相加可以抵消，所以flag的数量可以有很多个，其余情况均是flag==3方可满足题目要求。

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for (int i = 0; i < A.length; i++){
            sum += A[i];
        }
        //总和必须能被3整除
        if (sum % 3 != 0){
            return false;
        }
        int avg = sum/3;
        int part = 0;
        int flag = 0;
        for (int i = 0; i < A.length; i++){
            part += A[i];
            //每部分和达到后重置part
            if (part == avg){
                part = 0;
                flag += 1;
            }
        }
        if (avg == 0 && flag >= 3){
            return true;
        }else if (flag == 3){
            return true;
        }
        return false;
    }
}
```