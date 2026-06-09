### 解题思路
白板Bugfree挑战，代码还是挺丑的，用了三次才通过，主要是没有考虑AB不用交换也可以的情况，时间复杂O(n)，空间复杂O(1)

### 代码

```java
class Solution {
    public int minDominoRotations(int[] A, int[] B) {
        //count the number of elements
        int[] elementA = new int[7];
        int[] elementB = new int[7];
        for (int i : A){
            elementA[i] += 1;
        }
        for (int i: B){
            elementB[i] += 1;
        }
        int swap = -1;
        for (int i=1; i<7; i++){
            if (A.length<=elementA[i]+elementB[i]){
                swap = i;
            }
        }
        if (swap==-1) return -1;

        int ansB = 0;
        int ansA = 0;
        for (int i = 0; i<A.length; i++){
            if (A[i]==swap&&B[i]==swap){
                continue;
            }
            else if(A[i]==swap){
                ansA++;
            }
            else if(B[i]==swap){
                ansB++;
            }else{
                return -1;
            }
        }
        return Math.min(ansA, ansB);
    }
}
```