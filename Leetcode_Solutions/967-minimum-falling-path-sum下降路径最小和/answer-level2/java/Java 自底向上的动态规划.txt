#### 使用两个数组来保存中间的结果
```
class Solution {
    public int minFallingPathSum(int[][] A) {
        int len=A.length;
        if(len==0)return 0;
        int[] res=new int[len];
        for(int i=0;i<len;i++)res[i]=A[len-1][i];
        int[] temp=new int[len];
        for(int i=len-2;i>=0;i--){
            for(int j=0;j<len;j++){
                if(j==0){
                    temp[j]=A[i][j]+Math.min(res[j],res[j+1]);
                }else if(j==len-1){
                    temp[j]=A[i][j]+Math.min(res[j-1],res[j]);
                }else{
                    temp[j]=A[i][j]+Math.min(res[j],Math.min(res[j-1],res[j+1]));                    
                }
            }
            System.arraycopy(temp, 0, res, 0, len);
        }
        int min=res[0];
        for(int i:res)min=Math.min(min,i);
        return min;
    }
}
```