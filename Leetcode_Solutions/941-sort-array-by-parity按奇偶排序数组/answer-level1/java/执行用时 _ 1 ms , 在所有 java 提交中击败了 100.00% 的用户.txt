```
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int[] B=new int[A.length];
        int start=0,end=A.length-1;
        for(int i=0;i<A.length;i++){
            if(A[i]%2==0){
                B[start++]=A[i];
            }else{
                B[end--]=A[i];
            }
        }
        return B;
    }
}
```
使用双指针，碰到偶数就偶数放到前面，碰到奇数将奇数放在后面

