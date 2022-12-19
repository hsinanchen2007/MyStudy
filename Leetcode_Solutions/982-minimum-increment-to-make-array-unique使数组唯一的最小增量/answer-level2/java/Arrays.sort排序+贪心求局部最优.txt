### 解题思路
此处撰写解题思路

### 代码

```java
import java.util.Arrays;

class Solution {
    public int minIncrementForUnique(int[] A) {
             int result = 0;

        //先进行从小到大的排序
   Arrays.sort(A);

        //System.out.println("after resort:" + Arrays.toString(A));

        //使用贪心算法，求局部最优解
        //通过for循环，从长度为0的局部最优开始，逐渐拓展到全长度的最优
        //下一个的最优，基于前一个最优的决定
        for (int i = 1; i < A.length; i++) {
            //局部最优的解法是，最后一个数字做到比倒数第二个数字至少大1即可

            //因为排序过，只需要解决最后两位相等的情况;还要解决，前面的数组增加过后比当前数字大的情况
            if (A[i] <= A[i - 1]) {
                int oldValue = A[i];
                //System.out.println("before change:" + Arrays.toString(A));
                A[i] = A[i - 1] + 1;
                //System.out.println("after change:" + Arrays.toString(A));
                result = result + (A[i] - oldValue);
            }


        }


        return result;   }
}
```