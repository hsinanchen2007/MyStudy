**方法一：最容易想到的暴力法**

话不多说，先上执行结果（本以为会超时，没想到还能通过！！！）

![1.jpg](https://pic.leetcode-cn.com/41596b27c05d76d035131fde6070ab71e9101bb3222b42822142057aeb9a24c2-1.jpg)

1660ms，oh my god，要是给面试官来这么个程序，估计没人敢要了吧！

```
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        if (nums.length == 1 && k == 1)
            return (double)nums[0];
        int max = Integer.MIN_VALUE;
        for (int i = 0; i <= nums.length - k; i++) {
            int sum = 0;
            for (int j = i; j < i + k; j++) {
                sum += nums[j];
            }
            if (sum > max)
                max = sum;
        }
        return (double)max / k;
    }
}
```
**方法二：进阶滑动窗口**

想到暴力法每次都会计算一次求和，但是每次移动一位，中间有很多重复的计算；
于是，想到每次计算都只加一个新的后面的数，并减去前面一个移出去的数即可
时间复杂度O（n）；

![2.jpg](https://pic.leetcode-cn.com/440c23e77508bfc53a5a80273d2ae4e7ad71e80c70866fdbd4592d0208d7001d-2.jpg)

果然，3ms，击败99%！！这才是面试官想要的题解
```
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += nums[i];
        int temp = sum; 
        for (int i = k, j = 0; i < nums.length; i++) {
            temp += nums[i];
            temp -= nums[j++];
            if (temp > sum)
                sum = temp;
        }
        return (double)sum / k;
    }
}
```

