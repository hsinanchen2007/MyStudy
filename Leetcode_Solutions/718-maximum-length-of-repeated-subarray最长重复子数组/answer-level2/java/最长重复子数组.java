### 解题思路

看代码吧

### 代码

```java
class Solution {
    public int findLength(int[] A, int[] B) {
       int firstLeft = A.length -1;
       int firstRight = firstLeft; 
       int secondLeft = 0;
       int secondRight = 0;
       int maxEqualLen = 0;
       while(true) {

           int compareLen = Math.min(firstRight-firstLeft,
                                     secondRight-secondLeft) + 1;
           if(compareLen < maxEqualLen) {
               return maxEqualLen;
           }
           int equalsLen = 0;
           int thisMaxEquals =0;
           for(int i=0; i < compareLen ;i++) {
               if(A[firstLeft+i] == B[secondLeft+i]) {
                   equalsLen++;
               } else {
                   if(equalsLen > thisMaxEquals) {
                       thisMaxEquals = equalsLen;
                   }
                   equalsLen=0;
                   if(compareLen-i-1 <= maxEqualLen) {
                       break;
                   }
               }
           }
           if(equalsLen > thisMaxEquals) {
                thisMaxEquals = equalsLen;
           }
           if(thisMaxEquals > maxEqualLen) {
               maxEqualLen = thisMaxEquals;
           }
           if(firstLeft == 0 && secondLeft==secondRight) {
               break;
           }
           if(secondRight == B.length -1) {
               secondLeft++;
           } 
           if(firstLeft > 0) {firstLeft--; }
           if(secondRight < B.length -1) {secondRight++;} 
       }
       return maxEqualLen;
    }
}
```