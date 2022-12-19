```
100%
100%
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        if(A==null || A.length<3){// 边界条件
            return false;
        }
        // 首先判断数组元素总和是否可以被3整除
        int sum=0;
        int temp=0;
        int count=0;
        for(int i=0;i<A.length;i++){
            sum+=A[i];
        }
        if(sum%3!=0){//不能则返回false
            return false;
        }
        temp=sum/3;
        sum=0;
        //能则判断是否可以划分
        for(int j=0;j<A.length-1;j++){//留最后一位保证一定能三分
            sum+=A[j];
            if(sum==temp){
                count++;
                if(count==2){
                    return true;
                }
                sum=0;
            }
        }
        /**if(count>=3){//>3是和为0的情况
            return true;
        }*/
        return false;
    }
}
```
