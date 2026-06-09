### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/f3fd728d707698f8332244b3cb1c9161b5805b325f9953f3551fe55ea4af07e3-image.png)


### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {

        if(A.length < 3){
            return false;
        }

        int sum = 0;
        for(int i = 0 ; i < A.length ; i++){
            sum += A[i];
        }
        
        if(sum % 3  != 0){
            return false;
        }

        int s = sum/3;
        
        int flagSum = 0;
        int flag1 = -1;  //分割位置一
        int flag2 = -1;  //分割位置二

         for(int i = 0 ;i < A.length ;i++){

            flagSum = flagSum + A[i];
            if(flagSum == s){
                if(flag1 == -1){
                    flag1 = i;
                    flagSum = 0;    //找到分割点位置一后，flagSum 清零.
                }else{
                    flag2 =i;
                    break;
                }
             
            }
        }

        if(flag2 < A.length-1 && flag1 != -1 && flag2 != -1){
            return true;
        }else{
            return false;
        }

    }
}
```