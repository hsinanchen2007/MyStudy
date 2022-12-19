### 代码

```java
class Solution {
    public int minDominoRotations(int[] A, int[] B) {
        int[] aCount = new int[6];
        int[] bCount = new int[6];
        boolean[] numMax = new boolean[6];
        int tempCount = 0;
        int ans = 20001;
        int index = 0;
        int length = A.length;
        //acount, bcount
        for(int i = 0; i < length; i++){
            aCount[A[i]-1]++;
            bCount[B[i]-1]++;
        }
        //numMax
        for(int j = 0; j < 6; j++){
            numMax[j] = aCount[j] >= bCount[j] ? true : false;
        }
        //6 iterations
        for(int k = 0; k < 6; k++){
            index = 0;
            tempCount = 0;
            if(numMax[k]){
                //A
                for(; index < length && aCount[k] > 0; index++){
                    if(A[index] == k+1){
                        continue;
                    }
                    else{
                        if(B[index] != k+1){
                            break;
                        }
                        else{
                            tempCount++;
                        }
                    }
                }
                if(index == length){
                    ans = tempCount < ans ? tempCount : ans;
                }
            }
            else{
                //B
                for(; index < length && bCount[k] > 0; index++){
                    if(B[index] == k+1){
                        continue;
                    }
                    else{
                        if(A[index] != k+1){
                            break;
                        }
                        else{
                            tempCount++;
                        }
                    }
                }
                if(index == length){
                    ans = tempCount < ans ? tempCount : ans;
                }
            }
        }
        
        return ans == 20001 ? -1 : ans;
    }
}
```