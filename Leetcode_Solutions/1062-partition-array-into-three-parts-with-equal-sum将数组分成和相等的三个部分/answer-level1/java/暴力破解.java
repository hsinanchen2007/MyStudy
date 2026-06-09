执行用时：1ms,消耗内存：45MB
# 解题思路：
先通过约束判断数组A的长度是否大于3，小于3为false，再判断和是否可被3整除，不可以返回false,最后对数组和除3获得每部分和，依次判断是否存在这样的三部分，存在返回true；否则为false
代码：
```
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        if(A.length<3)
        return false;
        int sum=0;
        for(int i=0;i<A.length;i++){
            sum=sum+A[i];
        }
        int a=0;
        if(sum!=0){
          if(sum%3!=0)
             return false;
         a=sum/3;
        }
           
         int b=0;
         int c=0;
         for(int j=0;j<A.length;j++){
             b=b+A[j];
             if(b==a && c<2){
                c++;
                b=0; 
                if(j==(A.length-1)) 
                return false;  
             }
         }
         if(c==2 && b==a)
         return true;
         else
         return false;


    }
}
```
