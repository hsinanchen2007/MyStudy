思路：
    因为只存在负数最小值和正数最大值的排序问题，即给定数组最左端和最右端的大小问题。因此定义两个索引（left、right）进行首尾对比，将大的一个存入结果数组，小的进行下一轮对比。以此类推。

```
public static int[] sortedSquares(int[] A){
        //定义一个存放结果的数组
        int[] result = new int[A.length];
        //结果数组索引
        int index = A.length-1;
        //原数组右索引
        int right = A.length-1;
        //原数组左索引
        int left = 0;
        //左索引大于右索引时即计算完成
        while (left <= right) {
            //若右索引大于左索引，将右索引计算结果存入结果数组，原数组右索引--
            if (A[left] * A[left] < A[right] * A[right]){
                result[index] = A[right] * A[right];
                right--;
            }
            //若左索引大于右索引，将左索引计算结果存入结果数组，原数组左索引++
            else {
                result[index] = A[left] * A[left];
                left++;
            }
            //存入一个元素后，维护结果数组索引
            index--;
        }
        return result;
    }
```

时间复杂度：O(n)
