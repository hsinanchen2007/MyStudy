### 解题思路
将数组和三等分，每部分都是sum/3；只要判断第一部分和第二部分是否为sum/3即可；注意：第二部分不能占剩余数组全部，即第二部分的尾不能是数组长度。

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum=0;
        //求A的和
        for(int i=0;i<A.length;i++){
            sum += A[i];
        }
        if(sum%3!=0){
            return false;
        }
        int sum1=0,sum2=0;
        for(int j=0;j<A.length;j++){
            sum1 += A[j];
            if(sum1==(sum/3)){
                for(int k=j+1;k<A.length;k++){
                    sum2 += A[k];
                    //第二部分不能将剩余部分全占
                    if(sum2==(sum/3) && k!=(A.length-1)){
                        return true;
                    }
                }   
            }
        }
        return false;
    }
}
```