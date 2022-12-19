### 解题思路
用辅助数组存放每个数出现的次数，由于A[i]的范围为0~40000，所以可以直接用数组下标存放原数组A[i]的值。
每个位置只能放一个数，循环处理B，使处理后的B的每个位置都为1.

### 代码

```java
class Solution {
    /*
     * 执行用时 :5 ms, 97.81%
     * 内存消耗 :46.3 MB, 84.31%
     */
    public int minIncrementForUnique(int[] A) {
        if (A == null || A.length == 0)
            return 0;
        int len = A.length;
        int[] B = new int[40001];
        int bIndex = 0; //B最大的索引位置
        for (int i = 0; i < len; i++) {
            B[A[i]]++;
            if (bIndex < A[i])
                bIndex = A[i];
        }
        int surplus = 0;  //总共多余的数
        int ans = 0;
        /**
         * i 0 1 2 3 4 5
         * A 1 1 2 2 3 5
         * B   2 2 1 0 1
         *     1 3 1 0 1
         *     1 1 3 0 1
         *     1 1 1 2 1
         *     1 1 1 1 2
         */
        for (int i = 0; i <= bIndex; i++) {
            if (B[i] == 0 && surplus > 0)  //当前位置没有数，且前面位置有多余的没安排
                surplus--;  //多余的安排一下
            else if (B[i] > 1)  //当前位置就有多余的，需要更新总多余的数目
                surplus += B[i] - 1;
            ans += surplus;  //每个位置多余的数都要移动到下一个位置
        }
        //最后一个位置可能还有多余的，需要依次安排。
        return ans + (surplus - 1) * surplus / 2;
    }
}
```