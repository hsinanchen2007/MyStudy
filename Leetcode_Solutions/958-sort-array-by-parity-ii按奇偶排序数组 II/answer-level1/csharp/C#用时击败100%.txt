![922.png](https://pic.leetcode-cn.com/027a771bb02768c126fc14bc334a0974cb1be80aa77634cc03caf85913337490-922.png)

# 思路
错误的位置是成对出现的,如果有一个偶数不在对应位置，就有一个奇数不在对应位置。所以，我们用双指针，`i`指向偶数位置，`j`指向奇数位置。如果`i`所指的元素为奇数，`i`停止+2。`j`在往后遍历就一定会找到一个在错误位置的元素。如果`i`与`j`所指的元素都是错误的，就可以做交换，再恢复自增。直到`i`或`j`超出`A`数组边界。这样可以减少很多不必要的操作。


# 代码
```
public class Solution {
    public int[] SortArrayByParityII(int[] A) {
        int i = 0;
        int j = 1;
        while (i < A.Length && j < A.Length)
        {
            if(A[i] % 2 != 0&& A[j] % 2 == 0)
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
            if (A[i] % 2 == 0) i += 2;
            if (A[j] % 2 != 0) j += 2;
        }
        return A;
        
    }
}
```
