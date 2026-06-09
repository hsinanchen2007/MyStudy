执行用时 :4 ms, 在所有 Java 提交中击败了95.71% 的用户
这题好绕，但是难度不至于是困难，只是写起来很烦。
我的方法是先排除1个数不对和全0的情况，然后分组，每组头尾都是1，根据每组头尾1的位置，判断组长度对不对，0够不够，再判断组内是否匹配。完整的流程需要遍历三次，复杂度O(n)
各种方法感觉大同小异，关键还是宁愿多分类讨论也不要多遍历。

代码如下：
```
class Solution {
    public int[] threeEqualParts(int[] A) {
        int ones = 0;
        int[] NO = new int[]{-1, -1};
        for (int i : A) ones += i;
        if (ones % 3 != 0) return NO;               //1个数是三的倍数
        if (ones == 0) return new int[]{0, 2};      //都是0，这个方法只能处理有1的数组
        ones /= 3;
        int len = A.length;
        int[] onePos = new int[6];                  //存放组头、组尾的1的位置
        int count = 0;
        for (int i = 0; i < len; ++i) {
            count += A[i];
            //组头1
            if (A[i] == 1 && (count - 1) % ones == 0) onePos[2 * ((count - 1) / ones)] = i;
            //组尾1
            if (A[i] == 1 && count % ones == 0) onePos[2 * (count / ones) - 1] = i;
        }
        if (onePos[1] - onePos[0] != onePos[3] - onePos[2] ||
                onePos[5] - onePos[4] != onePos[3] - onePos[2]) return NO;
        //组的长度不同
        //组外0个数，共四组组外0
        int[] zeros = new int[4];
        zeros[1] = onePos[2] - onePos[1] - 1;
        zeros[2] = onePos[4] - onePos[3] - 1;
        zeros[3] = len - onePos[5] - 1;
        //组外0不够
        if (zeros[1] < zeros[3] || zeros[2] < zeros[3]) return NO;
        //组内匹配
        for (int i = onePos[0], j = onePos[2], k = onePos[4]; i < onePos[1]; ++i, ++j, ++k) {
            if (A[i] != A[j] || A[i] != A[k]) return NO;
        }
        return new int[]{onePos[1] + zeros[3], onePos[3] + zeros[3] + 1};
    }
}
```
