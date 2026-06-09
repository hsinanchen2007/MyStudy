数组有序，则数组的第一个元素的平方与最后一个元素的平方中的最大值一定为整个数组的最大值，故给定2个指针，一个为从0开始，一个为最大值。

```
public int[] sortedSquares(int[] A) {
        int maxIndex = A.length;
        int beforeIndex = 0;
        int afterIndex = maxIndex-1;
        int head = maxIndex-1;
        int[] resultArr = new int[maxIndex];
        while(beforeIndex != afterIndex){
            if(A[beforeIndex]*A[beforeIndex] >= A[afterIndex]*A[afterIndex]){
                resultArr[head--] = A[beforeIndex]*A[beforeIndex++];
            }else{
                resultArr[head--] = A[afterIndex]*A[afterIndex--];
            }
        }
        resultArr[0] = A[beforeIndex]*A[beforeIndex];
        return resultArr;
    }
```