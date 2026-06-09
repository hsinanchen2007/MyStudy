# 1. Approach 1: Direct 
```java
// 分析运算规律，减少不必要的计算，从而降低时间复杂度和空间复杂度；
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int length = A.length;
        
        for(int[] rowArray: A)
        {
            // 若 length 为奇数，则对行数组中间的数值取反；
            // 取反：newValue = 1-oldValue;
            if(length%2 == 1)
                    rowArray[length/2] = 1-rowArray[length/2];
            
            // 遍历二维数组；
            for(int i=0; i<length/2; i++)
            {
                // 若左右两侧元素数值不等，则变换后值不变，不执行任何操作；
                // E.g. Before: 1...0; After: 1...0；
                // 若左右两侧元素数值相等，则变换后值取反；
                // E.g. Before: 1...1; After: 0...0;
                if(rowArray[i] == rowArray[length-i-1])
                {
                    rowArray[i] = 1-rowArray[i];
                    rowArray[length-i-1] = 1-rowArray[length-i-1];
                }
            }
        }
        return A;
    }
}
```