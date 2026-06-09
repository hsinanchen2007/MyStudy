

# 1ms

```
class Solution {
    public boolean containsDuplicate(int[] nums) {
        if (nums.length < 2) {
            return false;
        }
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for (int i: nums) {
            if (i < min) {
                min = i;
            }
            if (i > max) {
                max = i;
            }
        }
        int[] arr = new int[(max - min)/32 + 1];
        for (int i: nums) {
            int x = i - min;
            int pos = x / 32;
            int mask = 1 <<  (x % 32);
            if ((arr[pos] & mask) != 0) {
                return true;
            } else {
                arr[pos] |= mask;
            }
        }
        return false;
    }
}

```


# Method 2, 0 ms

```
class Solution {
    public boolean containsDuplicate(int[] nums) {
        if (nums.length < 1 || nums[0] == 237384 || nums[0] == -24500) {
            return false;
        }
        boolean[] bs = new boolean[2048];
        for (int n : nums) {
            if (bs[n & 2047]) {
                return true;
            } else {
                bs[n&2047] = true;
            }
        }
        return false;
    }
}
```


以上，为大神之作，还没细读，大家可以先自行分析~


# 分析 0ms

不太明白237384，-24500的由来，但是大概明白了思路。

创建一个长度为2048的boolean数组，（后面有n&2047操作，所以不会角标越界），
根据nums中每个元素的值把boolean数组中对应位置的值改为true：
```
bs[n&2047] = true;
```
2047的二进制为11个1，`11111111111`

**关键点** 
n&2047, 此为：截取n的最后11位bits值。例如：
n = 45, 对应二进制`101101`。 

这样我们就可以把Boolean数组角标在45的值改为true，意味着已经存在改值。
下一次再遇到45，就会发现改值已经为true，表明已经存在过，则可直接返回true。

**BIG PROBLEM**
代码确实通过了测试，但存在一个严重的问题，经过测试，某些正数和负数的最后11位bits存在相等的情况，例如：
-50，`11111111111111111111111111001110`
1998,                     `11111001110`
意味着，如果数组中只有-50和1998同时存在，该方法会返回true，然而理应返回false。

即便如此，能通过最最基础的知识把问题搞定，已经是相当不易了，感谢大神0ms思路。

对不起，方法1还没读懂~