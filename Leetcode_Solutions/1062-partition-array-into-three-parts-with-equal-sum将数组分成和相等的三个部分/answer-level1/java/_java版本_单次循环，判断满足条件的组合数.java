最先想到的就是这种办法
# 解题思路
1. 判断
- 如果数组是空
- 数组元素个数<3
- 数组之和不能被3整除
这三种情况直接返回`false`

2. 算出每部分要对比的数值`target`，值为数组的每个数之和除以3
3. 定义一个计数器`parts`，用来计算当前有几个部分满足`target`
4. 定义临时变量`partSum`，用来存储当前“部分”的和
5. 循环数组，叠加当前元素的值并将结果存入`partSum`中，然后判断`partSum`与`target`是否相等。如果相等，则将计数器`parts`+1，并且将`partSum`清0，意为当前部分已找到，开始重新结算下一部分
6. 最终判断`parts>=3`是否成立。大于3的情况，有且只有一种情况就是`target`为0，可能有N个部分，最终这N个部分都可以合并成3个部分，比如`[1,-1,1,-1,1,-1,1,-1]`，这种情况`parts`为4, `target`为0，每一部分分别为`[1,-1], [1,-1], [1,-1], [1,-1]`。可以合并成3个，即`[1,-1], [1,-1], [1,-1,1,-1]`

# 代码
```java
import java.util.stream.IntStream;

public class CanThreePartsEqualSum {

    public static void main(String[] args) {

        // [0,2,1,-6,6,-7,9,1,2,0,1]: true
        // [0,2,1,-6,6,7,9,-1,2,0,1]: false
        // [3,3,6,5,-2,2,5,1,-9,4]: true
        // [1,-1,1,-1]: true
        // [10,-10,10,-10,10,-10,10,-10]: true
        int[] A = new int[]{10, -10, 10, -10, 10, -10, 10, -10};
        System.out.println(new Solution().canThreePartsEqualSum(A));
    }
}

class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        // 数组为空或元素个数小于3个返回false
        if (A == null || A.length < 3) return false;
        int sum = IntStream.of(A).sum();    // 求和
        // 不能整除也返回false
        if (sum % 3 > 0) return false;
        int target = sum / 3;   // 每个部分的和
        int partSum = 0;    // 当前部分的和
        int parts = 0;   //  当前已有几部分满足
        for (int i = 0; i < A.length; i++) {
            partSum += A[i];
            if (partSum == target) {
                parts++;
                partSum = 0;
            }
        }
        // 分析：flag >= 3的意思是，如果超过3个，而每部分的和还一样，证明有N个部分的和是0，可以归到任何一个部分中，最终结果可看做3个
        // 例如[1,-1,1,-1,1,-1,1,-1]，这里的flag = 4，但是可以把最后一个1,-1归到第三部分中，也就是[1,-1][1,-1][1,-1,1,-1]
        // 所以判断是成立的
        return parts >= 3;
    }
}