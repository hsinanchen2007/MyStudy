### 解题思路
通过分析可知，数组长度为2n，必然会成对出现，要使得最小数之和最大，我们必须尽量让小的数不与大数相结合，据此我们对数组排序，每隔两个数取得数必然是较小数，而且必然不可能与大数碰头，理解这一点即可，程序是很好写的，没有什么技术含量。

### 代码

```java
class Solution {
    public int arrayPairSum(int[] nums) {
        Arrays.sort(nums);
        int sum = 0;
        for(int i = 0;i<nums.length;i+=2) {
            sum = sum+nums[i];
        }
        return sum;
    }
}
```