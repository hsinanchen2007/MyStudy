查找数组中两数之差的绝对值是k, 首先想到也最简单的就是排序之后进行计算
`定义一个起始指针start 随着i的增加找到差值为k的时候 start++, i++`
中间会遇到两种特殊情况
1. 当遇到一串相同数字的时候 那么只需要i不断前进即可 当遇到差值为k的时候记录下prev = nums[start] 然后跳过所有等于prev的start
2. 就是当差值大于k的时候 我们需要start进1 此时需要判断增长后的start是否等于i 只有相等的情况才需要i也进1 否则需要i--
![1574844420(1).png](https://pic.leetcode-cn.com/b4368ec329ca7fe3e4f37319a1ce5809a9dcaf04186ef0743fc606e2e44f936e-1574844420\(1\).png)

```java
    public int findPairs(int[] nums, int k) {
        if(k < 0) return 0;
        Arrays.sort(nums);
        int start = 0, count = 0, prev = 0x7fffffff;
        for (int i = 1; i < nums.length; i++) {
            if(nums[i] - nums[start] > k || prev == nums[start]) {
                if (++start != i) i--;
            }else if (nums[i] - nums[start] == k) {
                prev = nums[start++];
                count++;
            }
        }
        return count;
    }
```