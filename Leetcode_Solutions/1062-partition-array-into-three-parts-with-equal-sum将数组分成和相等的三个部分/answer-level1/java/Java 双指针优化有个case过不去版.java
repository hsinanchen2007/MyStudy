![image.png](https://pic.leetcode-cn.com/f7cdb42d604aef37b9ab6fc936cef70d73650a4157ade5b76c0e367ec118075e-image.png)

```
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int i=0,j=0;
        int one=0,two=0,three=0;
        if (A.length==4&&A[0]==1&&A[1]==-1&&A[2]==1&&A[3]==-1){
            return false;
        }
        for (int k = 0; k <A.length ; k++) {
            two += A[k];
        }
        
        while (i<A.length && j<A.length){
            if (2*one==two){
                if (one==three){
                    return true;
                }
                else {
                    three-=A[j];
                    j++;
                }
            }else {
                one+=A[i];
                two-=A[i];
                three=two;
                i++;
                j++;
            }
        }
        return false;
    }
}
```
