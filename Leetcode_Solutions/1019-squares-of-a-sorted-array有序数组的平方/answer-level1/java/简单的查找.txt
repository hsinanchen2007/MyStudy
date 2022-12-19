### 解题思路
边界判断。。。思路想一会能想出来 边界判断能力还是欠缺。

### 代码

```java
class Solution {
    public int[] sortedSquares(int[] A) {
    int[] a = new int[A.length];
        int positiveIndex = 0;
        int negativeIndex = 0;
        for (int i=0;i<A.length;i++){
            if(A[i]<0){
                negativeIndex = i;
                continue;
            }
        }
        positiveIndex = negativeIndex+1;
        int i=0;
        while (i<A.length){
            if (negativeIndex<0){
                a[i]=A[positiveIndex]*A[positiveIndex];
                positiveIndex++;

                i++;
                continue;
            }
            if (positiveIndex>=A.length){
                a[i]= A[negativeIndex]*A[negativeIndex];
                negativeIndex--;

                i++;
                continue;
            }
            int rightNumber = A[positiveIndex];
            int leftNumber = -A[negativeIndex];
            if (negativeIndex>=0&&rightNumber>leftNumber){
                a[i] = leftNumber*leftNumber;
                negativeIndex--;
            }else if(positiveIndex<A.length) {
                a[i]= rightNumber*rightNumber;
                positiveIndex++;
            }

            i++;

        }
        return a;
    }
}
```