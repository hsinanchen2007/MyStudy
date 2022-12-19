一开始看的有点懵,后来明白了,这道题核心利用不等式关系+二分查找法
希望我的注释对你有帮助
```
public double FindMedianSortedArrays(int[] A, int[] B) {
        //确保A长度小于等于B
        if (A.Length > B.Length)
        {
            int[] temp = A;
            A = B;
            B = temp;
        }
        int iStart = 0;
        int iEnd = A.Length;
        //正常范围内
        while (iStart <= iEnd)
        {
            int i = (iStart + iEnd) / 2;//取中间索引 二分查找法
            //在索引i位置将A切为两半,A左半部分长度为i,右半部分为A.length-i;
            //在索引j位置将B切为两半,B左半部分长度为j,右半部分长度为B.length-j;
            //将A左半部分与B左半部分相加,A右半部分与B右半部分相加 有i+j=A.length-i+B.length-j 或A.length-i+B.length-j+1;
            //整合得到j的表达式
            int j = (A.Length + B.Length + 1 - 2 * i) / 2;
            //找到中位数时存在以下不等式关系
            //此时i偏小 继续二分查找并增大i
            if (i < iEnd && B[j - 1] > A[i])
            {
                iStart = i + 1;
            }
            //i偏大
            else if (i > iStart && A[i - 1] > B[j])
            {
                iEnd = i - 1;
            }
            //满足条件
            else
            {
                //边界值
                int maxLeft = 0;
                if (i == 0)
                {
                    maxLeft = B[j - 1];
                }
                else if (j == 0)
                {
                    maxLeft = A[i - 1];
                }
                else
                {
                    maxLeft = Math.Max(A[i - 1], B[j - 1]);
                }
                //奇数情况
                if ((A.Length + B.Length) % 2 == 1)
                {
                    return maxLeft;
                }
                //边界值
                int minRight = 0;
                if (i == A.Length)
                {
                    minRight = B[j];
                }
                else if (j == B.Length)
                {
                    minRight = A[i];
                }
                else
                {
                    minRight = Math.Min(B[j], A[i]);
                }
                //偶数情况
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
```