### 解题思路

这到题最难的地方在于，常数空间复杂度。

#### 首先进行分析个粗略的分析：

假设我们有个很大的bitmap，每一位都是0. 循环nums数组里的数，每个都在bitmap上记录一下，将其对应位设置为1。然后从位置1开始在bitmap上找，哪个位置上是0，就说明那个数就是没出现的最小的正整数。

这样的话，问题就可以解决了，申请个数组当bitmap用，长度为Integer.MAX_VALUE。而且对于这道题来说空间也是常数级别的，就是这个常数有点大。

#### 我们再把规模变小一点：

nums数组的长度就是N，“最小的没出现的正整数”最大是多少呢？比如最大是K，K没有出现过，那么K前边的数都出现过，为了让K最大，那么把N个数都排到K前面好了，也就是说K最大是N+1

也就是说，上面提到的bitmap的规模不用很大，反正K小于等于N+1，搞个数组N+1长度就行，但是呢，要求空间复杂度是常数，那么不能额外申请数组了，就想办法用现成的，毕竟题目会给个数组，我们想办法改改，利用现成的数组，算法题里不是有很多题解都是在现有的数组上操作的么。

题目给个N长度的，我们需要N+1长度的，怎么办？我们真的需要多来的一位么，不需要，如果真的循环到了N+1位，那么说明前N个数已经占满了，最后的结果就是K=N+1，所以多出来的一位不需要。

#### 接下来看看怎么标记：

首先负数不需要，因为找的是正整数，正整数从1开始，所以负数可以用0替代。

其次大于等于N+1的数也不需要，因为如果有个数等于N+1，那么前面N个位置塞下N-1个数，有个地方空着嘛。大于等于N+1的也用0替代

然后nums中元素的大小为[0,N], 所以他们的最高位符号位为0，没有被用到，可以用这一位来标记。0表示没有出现过，1表示出现过。

这样，循环一遍数组，在最高位上标记，然后再循环一遍数组，没被标记的就是答案。

下面代码写了好多注释，你可以仔细看看

### 代码

```java
import java.util.*;

class Solution {
    private static final int INVALID_NUMBER = 0;
    private static final int MASK = ~ Integer.MAX_VALUE; // 1000000.....00000 最高位

    /**
     * 从number去掉最高位，取出实际的数字
     */
    public int extractNumber(int number){
        return number & ~MASK;
    }
    
    /**
     * 通过最高位查询数是否存在
     * @param bitmap 就是int数组，我们只用最高位
     * @param number 要查number是否存在，1 <= number <= bitmap.length
     */
    public boolean getExist(int[] bitmap, int number) {
        // 索引要小于bitmap.length
        int index = number - 1;
        return (bitmap[index] & MASK) != 0;
    }

    /**
     * 设置number已经存在
     */
    public void setExist(int[] bitmap, int number) {
        // 索引要小于bitmap.length
        int index = number - 1;
        bitmap[index] = bitmap[index] | MASK;
    }

    public int firstMissingPositive(int[] nums) {
        int N = nums.length; // 数的个数
        int[] bitmap = nums; // 假设他们是两个数组，好理解一点

        // 将所有小于0和大于N的数都替换成0，不影响结果
        // 数组中的数除了0，都在[1,N]这个区间内
        for (int i = 0; i < N; i++) {
            if (nums[i] < 0) nums[i] = INVALID_NUMBER;
            if (nums[i] > N) nums[i] = INVALID_NUMBER;
        }

        // 每个位置上去掉最高位得到target
        // 每个数都在设置为存在
        for (int i = 0; i < N; i++) {
            int target = extractNumber(nums[i]);
            if (target == INVALID_NUMBER) continue; // 如果target等于0，说明没意义嘛，就忽略
            setExist(bitmap, target);
        }
        
        // 从1到N, 看哪个数不存在，说明就是最小的正整数
        for (int i = 1; i <= N; i++) {
            if (!getExist(bitmap, i)) return i;
        }

        // nums数组正好是从[1,2,3,4,5,6,.....,N-1,N]
        // 那么最小的没出现的正整数就是N+1
        return N+1;
    }
}
```