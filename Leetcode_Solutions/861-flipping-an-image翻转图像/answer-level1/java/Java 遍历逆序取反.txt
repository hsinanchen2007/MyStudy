
```java
class Solution {
    public int[][] flipAndInvertImage(int[][] A) throws RuntimeException {
        int lineNum = A.length;
        final int minLineNum = 1;
        final int maxLineNum = 20;
        
        //检查行数
        if (lineNum < minLineNum || lineNum > maxLineNum) {
            throw new RuntimeException("A的行数不在1-20之间");
        }
        
        //每行取反后的二维数组
        int[][] AResver = new int[lineNum][];
        for (int i = 0; i < lineNum; i++) {
            //检查每行的长度和行数是否一致
            int lineLen = A[i].length;
            if (lineLen != lineNum) {
                throw new RuntimeException("行的长度和A的长度不一致");
            }
            
            //每行的元素逆序并取反
            int[] lineResver = new int[lineLen];
            for (int j = lineLen - 1; j >= 0; j--) {
                int pixel = A[i][j];
                if (pixel < 0 || pixel > 1) {
                    throw new RuntimeException("值不是0或1");
                }
                lineResver[lineLen - j - 1] = 1 - A[i][j];
            }
            
            AResver[i] = lineResver;
        }

        return AResver;
    }
}
```