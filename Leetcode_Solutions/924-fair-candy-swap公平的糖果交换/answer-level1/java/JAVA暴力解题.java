### 解题思路
根据题目可以想到交换完后他们的糖果数是总的一半，所以我们可以分别求出爱丽丝的总糖果数、鲍勃的总糖果数、总糖果数的一半，用爱丽丝和鲍勃之间糖果数多的max(numa,numb) - 总糖果数的一半 得到的是他们要交换的糖果的大小的差值，利用循环遍历寻找符合差值的糖果就搞定
注意：要确定是谁比谁多

### 代码

```java
class Solution {
    public int[] fairCandySwap(int[] A, int[] B) {
        int numa=0,numb=0,nums=0,phase=0;
        int[] ans= new int[2];
        for(int a:A){
            numa+=a;
        }
        for(int b:B){
            numb+=b;
        }
        nums=(numa+numb)/2;
        phase=Math.max(numa,numb)-nums;
        
        for(int i =0;i<A.length;i++){
            for(int j = 0; j<B.length;j++){
                if(numa>numb){
                    if(A[i]-B[j]==phase)
                        {
                            ans[0]=A[i];
                            ans[1]=B[j];
                            return ans;
                        }  
                }else{
                    if(B[j]-A[i]==phase)
                        {
                            ans[0]=A[i];
                            ans[1]=B[j];
                            return ans;
                        }
                }
            }
        }
        return ans;
        }
       
}
```