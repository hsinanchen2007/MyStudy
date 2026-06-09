```
class Solution {
    public int[] countBits(int num) {
        int[] result=new int[num+1];
        result[0]=0;
        for (int i=1;i<num+1;i++){
            if(i==1) result[i]=1;
            else
               result[i] = (i&1)==0?result[i>>1]:result[i>>1]+1;
        }

        return result;
    }
}
```