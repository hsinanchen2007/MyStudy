### 解题思路
因为是整数数组，先求出数组的和并除以3，如果为小数则返回false
使用双指针，分别从左右两边对部分和进行计算

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        int avg = 0;

        int left = 0;
        int right = A.length-1;
        int leftSum = A[left];
        int rightSum = A[right];
        for(int i=0;i<A.length;i++){
            sum += A[i];
        }
        //System.out.println(sum);
        if(sum%3==0){
            avg = sum/3;
        }else{
            return false;
        }
        while(left+1 < right){
            if(leftSum==avg&&rightSum==avg){
                return true;
            }
            if(leftSum!=avg){
                leftSum += A[++left];
            }
            if(rightSum!=avg){
                rightSum += A[--right];
            }
        
        }
        return  false;
    
    }
}
```