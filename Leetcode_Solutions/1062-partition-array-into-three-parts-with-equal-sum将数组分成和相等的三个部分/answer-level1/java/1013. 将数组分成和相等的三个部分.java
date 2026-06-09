```
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for(int i = 0; i < A.length; i++){
            sum += A[i];
        }
        if(sum%3 != 0)  return false;   //总和必能被3整除
        else{
            sum /= 3;   //每部分的和应该为sum/3
            int tmp = 0;    //统计每部分的和
            int count = 0;  //计数器
            for(int j = 0; j < A.length; j++){
                tmp += A[j];
                if(tmp == sum){ //当部分和等于sum/3时，部分和清零，计数+1
                    tmp = 0;
                    count++;
                }
            }
           if(tmp == 0 && count >= 3)   //对于部分和等于0的情况，会存在计数大于3次，如[10,-10,10,-10,10,-10,10,-10]
            return true;
           else 
            return false;
        }
    }
}
```
