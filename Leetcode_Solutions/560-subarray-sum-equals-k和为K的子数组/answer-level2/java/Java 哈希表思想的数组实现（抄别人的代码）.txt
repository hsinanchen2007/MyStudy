    在用O（n^2）的方法解完题之后，看解答看到了哈希表的解法，但是自己使用之后发现，在Java的题解里，运算时间甚至排不到前50%，就看了一下Java排名第一的方法，是用数组类似模拟了哈希表的算法。速度要快很多，大概是下图的时间提升效率。

![QQ图片20200221115135.png](https://pic.leetcode-cn.com/7158b59ae17948daed0f609067f9774b05f31c66d839fc62b1a0229b9e2c3bf2-QQ%E5%9B%BE%E7%89%8720200221115135.png)

之后是模拟的代码：
```
    class Solution {
        public int subarraySum(int[] nums, int k) {
            int sum = 0;
            int min = Integer.MAX_VALUE;
            int max = Integer.MIN_VALUE;
            for (int n : nums) {
                sum += n;
                min = Math.min(min, sum);
                max = Math.max(max, sum);
            }
            int[] sums = new int[max - min + 1];//这里是用一个大数组来代替哈希表做存储，数组索引做key值，数组值做value；
            int count = 0;
            sum = 0;
            for (int n : nums) {
                sum += n;
                int target = sum - min - k;
                if (target >= 0 && target < sums.length) {
                    count += sums[target];
                }
                sums[sum - min]++;
            }
            if (k - min >= 0 && k - min < sums.length) {//这里是漏掉的单值的情况
                count += sums[k - min];
            }
            return count;
        }
    }
```
如果能看懂哈希表的做法，应该能理解这种做法，由于数组操作较快，所以提升了整体效率吧。