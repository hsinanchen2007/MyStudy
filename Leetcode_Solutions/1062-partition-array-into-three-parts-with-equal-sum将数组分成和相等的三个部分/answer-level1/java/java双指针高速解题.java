```
代码块
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for(int i:A){
            sum+=i;
        }
        if(sum%3!=0){
            return false;
        }
        int left=1,right=A.length-2,leftSum=A[0],rightSum=A[A.length-1],target=sum/3;
        //不能用leftSum=rightSum=0；
            while(leftSum!=target&&left<A.length){
                leftSum+=A[left++];
            }
            while(rightSum!=target&&right>=0){
                rightSum+=A[right--];
            }
            if(left<=right)
                return true;
            else
                return false;
    }
}
```
