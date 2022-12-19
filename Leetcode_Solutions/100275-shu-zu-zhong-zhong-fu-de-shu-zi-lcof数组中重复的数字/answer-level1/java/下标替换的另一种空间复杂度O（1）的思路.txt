### 解题思路
因为数组的数字在0-n-1之间，很自然想到要用下标去标记数组，那么怎么标记比较合适呢

试想 如果一个数字出现两次，那对应的下标的数字就肯定会被计算两次，我们采用递增的方式 ，每次增加数组的长度大小，方便后续进行计算取余和除法计算
上面的思路也就是 nums[nums[i] mod nums.length] += nums.length 被加后超过2*nums.length的数字的下标一定是出现过两次以上的数字ps mod的原因是防止前面的数据增加后 下标超过 nums.length导致indexoutofbounds

最后判断每一个下标的数字是否超过2即可 




### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        int len = nums.length;
        for (int i = 0; i < len; ++i)
        nums[nums[i]%len] += len;
        for(int i = 0; i < len; ++i)
        {
            if(nums[i]/len >1)
            return i;
        }
        return -1;

    }
}
```